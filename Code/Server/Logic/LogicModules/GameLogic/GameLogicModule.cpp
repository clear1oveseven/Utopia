#include "GameLogicModule.h"
#include "CsvConfigSets.h"
#include "ModuleDef/ModuleMgr.h"
#include "CommonModules/Log/LogModule.h"
#include "CommonModules/Timer/ITimerModule.h"
#include "CommonModules/Network/INetworkModule.h"
#include "Player/PlayerMgr.h"
#include "ModuleDef/IModule.h"
#include "Network/Protobuf/msg.pb.h"
#include "Network/Protobuf/test.pb.h"
#include "Network/Utils/NetworkAgent.h"
#include "Network/PlayerMsgHandler.h"
#include "Common/Macro/ServerLogicMacro.h"
#include "GameLogic/Scene/TestScene.h"
#include "behaviac/behaviac.h"
#include "Scene/Defines/SceneEventID.h"
#include "Common/EventDispatcher/EventDispacher.h"

static const char * AI_CONFIG_RELATE_PATH = "AI";
static const char * CSV_CONFIG_RELATE_PATH = "auto-csv/AutoCsvConfig";

GameLogicModule::GameLogicModule(ModuleMgr *module_mgr) : IGameLogicModule(module_mgr)
{
	m_csv_cfg_sets = new Config::CsvConfigSets();
	m_player_mgr = new GameLogic::PlayerMgr(this);
	m_player_msg_handler = new GameLogic::PlayerMsgHandler(this);
	m_new_scene = new GameLogic::TestScene(this);
}

GameLogicModule::~GameLogicModule()
{
	for (auto item : m_expired_csv_cfg_sets)
		delete item;
	m_expired_csv_cfg_sets.clear();
	delete m_csv_cfg_sets;
	if (nullptr != m_player_mgr)
	{
		delete m_player_mgr;
		m_player_mgr = nullptr;
	}
	delete m_new_scene; m_new_scene = nullptr;
}

EModuleRetCode GameLogicModule::Init(void *param)
{
	WaitModuleState(EMoudleName_TIMER, EModuleState_Inited, false);
	WaitModuleState(EMoudleName_Log, EModuleState_Inited, false);
	WaitModuleState(EMoudleName_Network, EModuleState_Inited, false);

	m_player_msg_handler->Init();
	m_cfg_root_path = *(std::string *)param;
	while ('/' == m_cfg_root_path.back() || '\\' == m_cfg_root_path.back())
		m_cfg_root_path.pop_back();
	m_cfg_root_path.append("/"); // format like: dir_path/

	behaviac::Workspace::GetInstance()->SetFilePath((m_cfg_root_path + AI_CONFIG_RELATE_PATH).c_str());
	behaviac::Workspace::GetInstance()->SetFileFormat(behaviac::Workspace::EFF_xml);

	std::string csv_cfg_path = m_cfg_root_path + CSV_CONFIG_RELATE_PATH;
	bool ret = m_csv_cfg_sets->Load(csv_cfg_path);

	m_state = ret ? EModuleState_Inited : EModuleState_Error;
	return ret ? EModuleRetCode_Succ : EModuleRetCode_Failed;
}

EModuleRetCode GameLogicModule::Awake()
{
	WaitModuleState(EMoudleName_Network, EModuleState_Awaked, false);

	bool ret = m_player_mgr->Awake("0.0.0.0", 10240);
	ret = ret && m_new_scene->Awake();
	return ret ? EModuleRetCode_Succ : EModuleRetCode_Failed;
}

EModuleRetCode GameLogicModule::Update()
{
	long long now_ms = GlobalServerLogic->GetTimerModule()->NowMs();
	m_player_mgr->Update(now_ms);
	// m_scene->Update(now_ms);
	m_new_scene->Update();
	return EModuleRetCode_Succ;
}

EModuleRetCode GameLogicModule::Release()
{
	return EModuleRetCode_Succ;
}

EModuleRetCode GameLogicModule::Destroy()
{
	m_new_scene->Destroy();
	m_player_msg_handler->Uninit();
	behaviac::Workspace::GetInstance()->Cleanup();
	return EModuleRetCode_Succ;
}

void GameLogicModule::HandlePlayerMsg(char *data, uint32_t data_len, GameLogic::Player *player)
{
	m_player_msg_handler->HandlePlayerMsg(data, data_len, player);
}

void GameLogicModule::ReloadConfig()
{
	Config::CsvConfigSets *new_cfg = new Config::CsvConfigSets();
	bool ret = new_cfg->Load(m_cfg_root_path + CSV_CONFIG_RELATE_PATH);
	if (ret)
	{
		if (nullptr != m_csv_cfg_sets)
			m_expired_csv_cfg_sets.push_back(m_csv_cfg_sets);
		m_csv_cfg_sets = new_cfg;

		m_new_scene->GetEvDispacher()->Fire(ES_ReloadConfig);
	}
	GlobalLog->Debug(LogModule::LOGGER_ID_STDOUT, "reload csv config {0}", ret ? "success" : "fail");
}

