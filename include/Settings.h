#ifndef SETTINGS_H
#define SETTINGS_H

#include <string>
#include <tinyxml2.h>

class Settings {
public:
    std::string username;
    int sensitivity;

    void Save(const std::string& path) const;
    static Settings Load(const std::string& path);

private:
    void Serialize(tinyxml2::XMLDocument& doc) const;
    void Deserialize(const tinyxml2::XMLDocument& doc);
};

#endif // SETTINGS_H
