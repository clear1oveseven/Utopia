#include "skill/SkillLevelConfig.h"
#include "CsvParser/csv.h"

namespace Config
{
     static const char * Field_Name_id = "id";
     static const char * Field_Name_level = "level";

    bool SkillLevelConfig::Init(std::map<std::string, std::string> kvPairs, ConfigCheckFunc func)
    {
        bool all_ok = true;
        all_ok = all_ok && kvPairs.count(Field_Name_id) > 0 && ConfigUtil::Str2BaseValue (kvPairs[Field_Name_id], id);
        all_ok = all_ok && kvPairs.count(Field_Name_level) > 0 && ConfigUtil::Str2BaseValue (kvPairs[Field_Name_level], level);
        if (all_ok && nullptr != func)
            all_ok &= func(this);
        return all_ok;
    }

    SkillLevelConfigSet::~SkillLevelConfigSet()
    {
        for (auto cfg : cfg_vec)
        {
            delete cfg;
        }
    }

    bool SkillLevelConfigSet::Load(std::string file_path)
    {
        io::CSVReader<2, io::trim_chars<' ', '\t'>, io::double_quote_escape<',', '\"'>, io::no_comment> csv_reader(file_path);
        csv_reader.read_header(io::ignore_extra_column,
            Field_Name_id,
            Field_Name_level
            );

        std::map<std::string, std::string> kvParis;
        kvParis[Field_Name_id] = "";
        kvParis[Field_Name_level] = "";

        bool all_ok = true;
        int curr_row = 0;
        while (csv_reader.read_row(
            kvParis[Field_Name_id],
            kvParis[Field_Name_level]
            ))
        {            
            if (++ curr_row <= 1)
                continue;
            if (kvParis[Field_Name_id].empty())
                continue;
            SkillLevelConfig *cfg = new SkillLevelConfig();
            all_ok &= cfg->Init(kvParis, cfg_check_fun);
            if (!all_ok)
                break;
            cfg_vec.push_back(cfg);
        }
        if (all_ok)
        {
            // gen key
            for (auto cfg : cfg_vec)
            {
                {
                    auto it = id_to_group.find(cfg->id);
                    if (id_to_group.end() == it)
                    {
                        auto ret_it = id_to_group.insert(std::make_pair(cfg->id, std::vector<SkillLevelConfig *>()));
                        if (!ret_it.second)
                        {
                            all_ok = false;
                            break;
                        }
                        it = ret_it.first;
                    }
                    it->second.push_back(cfg);
                }
            }
        }
        if (nullptr != cfg_set_check_fun)
        {
            all_ok = all_ok && cfg_set_check_fun(this);
        }
        return all_ok;
    }
}