#include "RequirementsManager.h"

void RequirementsManager::AddRequirement(const std::string& requirement) {
    requirements.push_back(requirement);
}

std::vector<std::string> RequirementsManager::GetRequirements() const {
    return requirements;
}

void RequirementsManager::ClearRequirements() {
    requirements.clear();
}
