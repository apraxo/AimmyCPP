#ifndef CONFIGS_H
#define CONFIGS_H

#include <string>
#include <unordered_map>

class Configs {
public:
    Configs(const std::string& path);
    void SaveSetting(const std::string& key, const std::string& value);
    std::string LoadSetting(const std::string& key) const;

private:
    std::string configFilePath;
    std::unordered_map<std::string, std::string> settings;

    void LoadSettings();
};

#endif // CONFIGS_H
