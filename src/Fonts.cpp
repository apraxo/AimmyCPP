#include "Fonts.h"

Fonts::Fonts() {
    // Initialization if needed
}

void Fonts::LoadFont(const QString& path) {
    fontDatabase.addApplicationFont(path);
}

QFont Fonts::GetFont(const QString& fontName, int size) {
    QFont font = fontDatabase.font(fontName, "", size);
    if (font.family().isEmpty()) {
        return QFont("Arial", size); // Fallback to Arial if font not found
    }
    return font;
}
