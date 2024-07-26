#ifndef FONTS_H
#define FONTS_H

#include <QFont>
#include <QFontDatabase>
#include <QString>

class Fonts {
public:
    Fonts();
    void LoadFont(const QString& path);
    QFont GetFont(const QString& fontName, int size);

private:
    QFontDatabase fontDatabase;
};

#endif // FONTS_H
