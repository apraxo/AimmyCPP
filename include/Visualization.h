#ifndef VISUALIZATION_H
#define VISUALIZATION_H

#include <QPainter>
#include <QString>

class Visualization {
public:
    void DrawRectangle(QPainter& painter, int x, int y, int width, int height);
    void DrawText(QPainter& painter, const QString& text, int x, int y);
};

#endif // VISUALIZATION_H
