#include "Visualization.h"

void Visualization::DrawRectangle(QPainter& painter, int x, int y, int width, int height) {
    painter.setPen(QPen(Qt::red, 2));
    painter.drawRect(x, y, width, height);
}

void Visualization::DrawText(QPainter& painter, const QString& text, int x, int y) {
    painter.setFont(QFont("Arial", 16));
    painter.setPen(Qt::black);
    painter.drawText(x, y, text);
}
