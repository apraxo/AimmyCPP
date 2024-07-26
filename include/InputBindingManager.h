#ifndef INPUTBINDINGMANAGER_H
#define INPUTBINDINGMANAGER_H

#include <unordered_map>
#include <functional>

enum class Keys {
    // Define relevant key values here
    KeyA,
    KeyB,
    // ...
};

class InputBindingManager {
public:
    void BindKey(Keys key, std::function<void()> action);
    void OnKeyPress(Keys key);
    void ClearBindings();

private:
    std::unordered_map<Keys, std::function<void()>> keyBindings;
};

#endif // INPUTBINDINGMANAGER_H
