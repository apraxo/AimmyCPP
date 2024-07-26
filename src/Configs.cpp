#include "Configs.h"
#include <fstream>
#include <sstream>

Configs::Configs(const std::string& path) : configFilePath(path) {
    LoadSettings();
}

void Configs::SaveSetting(const std::string& key, const std::string& value) {
    settings[key] = value;
    std::ofstream configFile(configFilePath, std::ios::app);
    if (configFile.is_open()) {
        configFile << key << "=" << value << std::endl;
    }
}

std::string Configs::LoadSetting(const std::string& key) const {
    auto it = settings.find(key);
    if (it != settings.end()) {
        return it->second;
    }
    return "";
}

void Configs::LoadSettings() {
    std::ifstream configFile(configFilePath);
    std::string line;
    while (std::getline(configFile, line)) {
        std::istringstream lineStream(line);
        std::string key, value;
        if (std::getline(lineStream, key, '=') && std::getline(lineStream, value)) {
            settings[key] = value;
        }
    }
}
