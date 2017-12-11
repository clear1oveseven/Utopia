#pragma once
#include <string>
#include <vector>
#include <map>
#include "Utils/ConfigUtil.h"

namespace Config
{
    struct CsvEffectHurtConfig // 
    {
        int id = 0 ;
        int value = 0 ;

        using ConfigCheckFunc = bool(*)(CsvEffectHurtConfig *item);
        bool Init(std::map<std::string, std::string> kvPairs, ConfigCheckFunc func);
    };

    struct CsvEffectHurtConfigSet
    {
        ~CsvEffectHurtConfigSet();
        CsvEffectHurtConfig::ConfigCheckFunc cfg_check_fun = nullptr;
        using ConfigSetCheckFunc = bool(*)(CsvEffectHurtConfigSet *items);
        ConfigSetCheckFunc cfg_set_check_fun = nullptr;
        bool Load(std::string file_path);
        
        std::vector<CsvEffectHurtConfig *> cfg_vec;
        std::map<int, CsvEffectHurtConfig *> id_to_key;
    };
}