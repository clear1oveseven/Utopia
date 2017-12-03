using System;
using System.Collections.Generic;
using LumenWorks.Framework.IO.Csv;
using System.IO;

namespace Config
{
    internal class FieldName_SkillConfig
    {
        public const string Field_Name_id = "id";
        public const string Field_Name_name = "name";
        public const string Field_Name_is_normal_attack = "is_normal_attack";
    }

    public class SkillConfig
    {
        public int id;
        public string name = string.Empty;
        public bool is_normal_attack;

        public delegate bool ConfigCheckFunc(SkillConfig cfg);
        public bool Init(Dictionary<string, string> kvPairs, ConfigCheckFunc func)
        {
            bool all_ok = true;
        all_ok = all_ok && kvPairs.ContainsKey(FieldName_SkillConfig.Field_Name_id) && ConfigUtil.Str2BaseValue (kvPairs[FieldName_SkillConfig.Field_Name_id], ref id);
        all_ok = all_ok && kvPairs.ContainsKey(FieldName_SkillConfig.Field_Name_name) && ConfigUtil.Str2Str (kvPairs[FieldName_SkillConfig.Field_Name_name], ref name);
        all_ok = all_ok && kvPairs.ContainsKey(FieldName_SkillConfig.Field_Name_is_normal_attack) && ConfigUtil.Str2BaseValue (kvPairs[FieldName_SkillConfig.Field_Name_is_normal_attack], ref is_normal_attack);
            if (all_ok && null != func)
                all_ok &= func(this);
            return all_ok;
        }
    }

    public class SkillConfigSet
    {
        public string errMsg = string.Empty;

        public SkillConfig.ConfigCheckFunc cfg_check_fun = null;
        public delegate bool ConfigSetCheckFunc(SkillConfigSet items);
        public ConfigSetCheckFunc cfg_set_check_fun = null;
        public List<SkillConfig> cfg_vec = new List<SkillConfig> ();
        public Dictionary<int, SkillConfig> id_to_key = new Dictionary<int, SkillConfig>();

        public bool Load(string file_path)
        {
            using (CsvReader csv = new CsvReader(new StreamReader(file_path), true))
            {
                csv.MissingFieldAction = MissingFieldAction.ReplaceByEmpty;
                string[] headers = csv.GetFieldHeaders();
                List<int> fieldIdxList = new List<int>();
                try
                {
                    fieldIdxList.Add(csv.GetFieldIndex(FieldName_SkillConfig.Field_Name_id));
                    fieldIdxList.Add(csv.GetFieldIndex(FieldName_SkillConfig.Field_Name_name));
                    fieldIdxList.Add(csv.GetFieldIndex(FieldName_SkillConfig.Field_Name_is_normal_attack));
                }
                catch (Exception e)
                {
                    errMsg = e.Message;
                    return false;
                }
                csv.ReadNextRecord();
                while (csv.ReadNextRecord())
                {
                    Dictionary<string, string> kvPairs = new Dictionary<string, string>();
                    foreach (int fieldIdx in fieldIdxList)
                    {
                        kvPairs[headers[fieldIdx]] = csv[fieldIdx];
                        
                    }
                    SkillConfig cfg = new SkillConfig();
                    if (!cfg.Init(kvPairs, cfg_check_fun))
                    {
                        errMsg = string.Format("SkillConfig Init Fail, row {0}", csv.CurrentRecordIndex);
                        return false;
                    }
                    cfg_vec.Add(cfg);
                }
            }

            foreach (var cfg in cfg_vec)
            {
                {
                    if (id_to_key.ContainsKey(cfg.id))
                    {
                        errMsg = string.Format("SkillConfigSet repeated key id = {0}", cfg.id);
                        return false;
                    }
                    id_to_key[cfg.id] = cfg;
                }
            }

            if (null != cfg_set_check_fun)
            {
                if (!cfg_set_check_fun(this))
                {
                    errMsg = "SkillConfigSet cfg_set_check_fun fail";
                    return false;
                }
            }

            return true;
        }
    }
}