#ifndef USERCONTROLLER_H
#define USERCONTROLLER_H

#include <vector>
#include <string>
#include <memory>
#include <algorithm>

class User {
public:
    std::string name;
    int age;
    std::string email;

    User(const std::string& name, int age, const std::string& email);
};

class UserController {
public:
    void AddUser(std::shared_ptr<User> user);
    std::shared_ptr<User> GetUser(const std::string& name) const;
    std::vector<std::shared_ptr<User>> GetAllUsers() const;
    void RemoveUser(const std::string& name);

private:
    std::vector<std::shared_ptr<User>> users;
};

#endif // USERCONTROLLER_H
