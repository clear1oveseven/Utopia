#pragma once

#include "ModuleDef/ModuleMgr.h"

class ITimerModule;
class INetworkModule;
class LogModule;
class NetworkAgent;

enum EServerLogicState
{
	EServerLogicState_Free,
	EServerLogicState_Init,
	EServerLogicState_Awake,
	EServerLogicState_Update,
	EServerLogicState_Release,
	EServerLogicState_Destroy,
	EServerLogicState_Max,
};

class ServerLogic
{
public:
	ServerLogic();
	virtual ~ServerLogic();

	virtual void SetInitParams(void *params) = 0;
	void Loop();
	void Quit();
	EServerLogicState GetState() { return m_state; }
	ModuleMgr * GetModuleMgr() { return m_module_mgr; }

	
	INetworkModule * GetNetworkModule();
	ITimerModule * GetTimerModule();
	LogModule * GetLogModule();
	NetworkAgent * GetNetAgent() { return m_network_agent; }

protected:
	virtual void SetupModules() = 0;
	virtual void ClearInitParams() = 0;
	bool Init();
	bool Awake();
	void Update();
	void Realse();
	void Destroy();

	EServerLogicState m_state = EServerLogicState_Free;
	ModuleMgr *m_module_mgr = nullptr;
	int m_loop_span_ms = 100;
	void * m_init_params[EMoudleName_Max];

	ITimerModule *m_timer_module;
	NetworkAgent *m_network_agent = nullptr;
};

