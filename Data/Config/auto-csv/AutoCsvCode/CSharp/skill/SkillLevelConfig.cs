using System;
using System.Collections.Generic;
using LumenWorks.Framework.IO.Csv;
using System.IO;

namespace Config
{
    internal class FieldName_SkillLevelConfig
    {
        public const string Field_Name_id = "id";
        public const string Field_Name_level = "level";
    }

    public class SkillLevelConfig
    {
        public int id;
        public int level;

        public delegate bool ConfigCheckFunc(SkillLevelConfig cfg);
        public bool Init(Dictionary<string, string> kvPairs, ConfigCheckFunc func)
        {
            bool all_ok = true;
        all_ok = all_ok && kvPairs.ContainsKey(FieldName_SkillLevelConfig.Field_Name_id) && ConfigUtil.Str2BaseValue (kvPairs[FieldName_SkillLevelConfig.Field_Name_id], ref id);
        all_ok = all_ok && kvPairs.ContainsKey(FieldName_SkillLevelConfig.Field_Name_level) && ConfigUtil.Str2BaseValue (kvPairs[FieldName_SkillLevelConfig.Field_Name_level], ref level);
            if (all_ok && null != func)
                all_ok &= func(this);
            return all_ok;
        }
    }

    public class SkillLevelConfigSet
    {
        public string errMsg = string.Empty;

        public SkillLevelConfig.ConfigCheckFunc cfg_check_fun = null;
        public delegate bool ConfigSetCheckFunc(SkillLevelConfigSet items);
        public ConfigSetCheckFunc cfg_set_check_fun = null;
        public List<SkillLevelConfig> cfg_vec = new List<SkillLevelConfig> ();
        public Dictionary<int, List<SkillLevelConfig>> id_to_group = new Dictionary<int, List<SkillLevelConfig>>();

        public bool Load(string file_path)
        {
            using (CsvReader csv = new CsvReader(new StreamReader(file_path), true))
            {
                csv.MissingFieldAction = MissingFieldAction.ReplaceByEmpty;
                string[] headers = csv.GetFieldHeaders();
                List<int> fieldIdxList = new List<int>();
                try
                {
                    fieldIdxList.Add(csv.GetFieldIndex(FieldName_SkillLevelConfig.Field_Name_id));
                    fieldIdxList.Add(csv.GetFieldIndex(FieldName_SkillLevelConfig.Field_Name_level));
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
                    SkillLevelConfig cfg = new SkillLevelConfig();
                    if (!cfg.Init(kvPairs, cfg_check_fun))
                    {
                        errMsg = string.Format("SkillLevelConfig Init Fail, row {0}", csv.CurrentRecordIndex);
                        return false;
                    }
                    cfg_vec.Add(cfg);
                }
            }

            foreach (var cfg in cfg_vec)
            {
                {
                    List<SkillLevelConfig> vec = null;
                    if (!id_to_group.TryGetValue(cfg.id, out vec))
                    {
                        vec = new List<SkillLevelConfig>();
                        id_to_group[cfg.id] = vec;
                    }
                    vec.Add(cfg);
                }
            }

            if (null != cfg_set_check_fun)
            {
                if (!cfg_set_check_fun(this))
                {
                    errMsg = "SkillLevelConfigSet cfg_set_check_fun fail";
                    return false;
                }
            }

            return true;
        }
    }
}