#include "InputBindingManager.h"

void InputBindingManager::BindKey(Keys key, std::function<void()> action) {
    keyBindings[key] = action;
}

void InputBindingManager::OnKeyPress(Keys key) {
    auto it = keyBindings.find(key);
    if (it != keyBindings.end()) {
        it->second();
    }
}

void InputBindingManager::ClearBindings() {
    keyBindings.clear();
}
