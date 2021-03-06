#include "EffectScriptConfig.h"
#include "EffectScript.h"
#include "Config/AutoCsvCode/effect/CsvEffectScriptConfig.h"
#include <assert.h>

namespace GameLogic
{
	std::shared_ptr<EffectBase> EffectScriptConfig::CreateEffect(SceneEffects *scene_effects, uint64_t effect_key) const
	{
		return std::make_shared<EffectScript>(this, scene_effects, effect_key);
	}

	bool EffectScriptConfig::InitCfg(const Config::CsvEffectScriptConfig * csv_cfg)
	{
		m_id = csv_cfg->id;
		m_class_name = csv_cfg->class_name;
		m_reversible = true;
		return true;
	}
}

