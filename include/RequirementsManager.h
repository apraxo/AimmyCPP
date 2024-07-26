#ifndef REQUIREMENTSMANAGER_H
#define REQUIREMENTSMANAGER_H

#include <vector>
#include <string>

class RequirementsManager {
public:
    void AddRequirement(const std::string& requirement);
    std::vector<std::string> GetRequirements() const;
    void ClearRequirements();

private:
    std::vector<std::string> requirements;
};

#endif // REQUIREMENTSMANAGER_H
