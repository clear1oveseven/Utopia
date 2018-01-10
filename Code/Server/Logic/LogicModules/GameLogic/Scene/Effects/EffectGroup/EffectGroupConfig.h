#pragma once

#include "GameLogic/Scene/Effects/EffectConfigBase.h"

namespace Config
{
	struct CsvEffectGroupConfig;
}

namespace GameLogic
{
	class SceneEffects;

	class EffectGroupConfig : public EffectConfigBase
	{
	public:
		virtual std::shared_ptr<EffectBase> CreateEffect(SceneEffects *scene_effects, uint64_t effect_key) const;

	public:
		bool InitCfg(const Config::CsvEffectGroupConfig *csv_cfg);
		int GetHurt() const { return m_hurt; }

	protected:
		int m_hurt = 0;
	};
}
