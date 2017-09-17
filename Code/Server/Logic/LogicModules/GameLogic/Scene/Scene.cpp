#include "Scene.h"
#include "SceneObject/SceneObject.h"
#include "SceneObject/Hero.h"

namespace GameLogic
{
	Scene::Scene(GameLogicModule *logic_module) : m_logic_module(logic_module)
	{

	}
	
	Scene::~Scene()
	{

	}

	bool Scene::Awake(void *param)
	{
		m_red_hero = std::make_shared<Hero>();
		this->AddObject(m_red_hero);
		m_blue_hero = std::make_shared<Hero>();
		this->AddObject(m_blue_hero);

		return true;
	}

	void Scene::Update(long long now_ms)
	{
		this->CheckSceneObjectsCache();
		for (auto it = m_scene_objs_cache.begin(); m_scene_objs_cache.end() != it; ++ it)
		{
			std::shared_ptr<SceneObject> scene_obj = it->second.lock();
			if (nullptr != scene_obj)
				scene_obj->Update(now_ms);
		}
		this->CheckSceneObjectsCache();
	}

	int64_t Scene::AddObject(std::shared_ptr<SceneObject> scene_obj)
	{
		if (nullptr == scene_obj)
			return 0;
		++m_last_scene_objid;
		if (m_last_scene_objid == INVALID_SCENE_OBJID)
			m_last_scene_objid = 1;
		if (m_scene_objs.find(m_last_scene_objid) != m_scene_objs.end())
			return 0;

		scene_obj->LeaveScene();
		scene_obj->SetScene(this);
		scene_obj->SetId(m_last_scene_objid);
		scene_obj->OnEnterScene(this);
		m_scene_objs[m_last_scene_objid] = scene_obj;
		m_scene_objs_cache[m_last_scene_objid] = scene_obj;
		return m_last_scene_objid;
	}


	void Scene::RemoveObject(int64_t objid)
	{
		if (m_red_hero->GetId() == objid || m_blue_hero->GetId() == objid)
			return;

		auto it = m_scene_objs.find(objid);
		if (m_scene_objs.end() == it)
			return;

		std::shared_ptr<SceneObject> scene_obj = it->second;
		scene_obj->OnLeaveScene(this);
		scene_obj->SetScene(nullptr);
		scene_obj->SetId(INVALID_SCENE_OBJID);
		scene_obj = nullptr;
		m_removed_scene_objids.insert(objid);
		m_scene_objs.erase(it);
	}

	void Scene::CheckSceneObjectsCache()
	{
		if (!m_removed_scene_objids.empty())
		{
			for (uint64_t objid : m_removed_scene_objids)
				m_scene_objs_cache.erase(objid);
			m_removed_scene_objids.clear();
		}
	}
}