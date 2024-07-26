#include "UserController.h"

// User class implementation
User::User(const std::string& name, int age, const std::string& email)
    : name(name), age(age), email(email) {}

// UserController class implementation
void UserController::AddUser(std::shared_ptr<User> user) {
    users.push_back(user);
}

std::shared_ptr<User> UserController::GetUser(const std::string& name) const {
    auto it = std::find_if(users.begin(), users.end(), [&name](const std::shared_ptr<User>& user) {
        return user->name == name;
    });
    return (it != users.end()) ? *it : nullptr;
}

std::vector<std::shared_ptr<User>> UserController::GetAllUsers() const {
    return users;
}

void UserController::RemoveUser(const std::string& name) {
    users.erase(std::remove_if(users.begin(), users.end(), [&name](const std::shared_ptr<User>& user) {
        return user->name == name;
    }), users.end());
}
