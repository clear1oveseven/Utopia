#include "SceneUnit.h"
#include <assert.h>
#include "SceneUnitModule.h"
#include "SceneUnitModules/SceneUnitTransform.h"
#include "Common/EventDispatcher/EventDispacher.h"
#include "Common/EventDispatcher/EventDispacherProxy.h"
#include "GameLogic/Scene/Defines/SceneEventID.h"
#include "GameLogic/Scene/NewScene.h"
#include "GameLogic/Scene/SceneUnit/SceneUnitEventProxy.h"

namespace GameLogic
{
	SceneUnit::SceneUnit()
	{
		m_event_dispacher = new ::EventDispacher();
		m_transform = std::make_shared<SceneUnitTransform>();
		this->AddModule(m_transform);
	}

	SceneUnit::~SceneUnit()
	{
		for (auto &&module : m_modules)
		{
			module = nullptr;
		}

		delete m_event_proxy;  m_event_proxy = nullptr;
		delete m_scene_event_proxy; m_scene_event_proxy = nullptr;
		delete m_event_dispacher; m_event_dispacher = nullptr;
	}

	void SceneUnit::EnterScene(NewScene *scene, uint64_t id)
	{
		if (m_inited)
			return;
		m_inited = true;
		m_started = false;

		{
			m_scene = scene;
			m_id = id;
			m_scene_event_proxy = new EventDispacherProxy(m_scene->GetEvDispacher());
			m_event_proxy = new SceneUnitEventProxy(m_event_dispacher, m_scene_event_proxy, this);
		}

		for (auto &&module : m_modules)
		{
			if (nullptr != module)
				module->Init(this);
		}
		for (auto &&module : m_modules)
		{
			if (nullptr != module)
				module->Awake();
		}

		this->GetEvProxy()->Fire(ESU_EnterScene);
	}

	void SceneUnit::LeaveScene()
	{
		this->GetEvProxy()->Fire(ESU_LeaveScene);

		if (m_inited)
		{
			m_inited = false;
			for (auto &&module : m_modules)
			{
				if (nullptr != module)
					module->Realse();
			}
			for (auto &&module : m_modules)
			{
				if (nullptr != module)
					module->Destroy();
			}
		}
		for (auto &&module : m_modules)
		{
			module = nullptr;
		}

		{
			delete m_event_proxy;  m_event_proxy = nullptr;
			delete m_scene_event_proxy; m_scene_event_proxy = nullptr;
			m_scene = nullptr;
		}
	}

	int Test(int a, int b)
	{
		return 0;
	}

	void SceneUnit::Update()
	{
		if (!m_started)
		{
			m_started = true;
			for (auto &&module : m_modules)
			{
				if (nullptr != module)
					module->Start();
			}
		}
		else
		{
			for (auto &&module : m_modules)
			{
				if (nullptr != module)
					module->Update();
			}
		}
	}
}

