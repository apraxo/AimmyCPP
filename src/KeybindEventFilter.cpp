#include "KeybindEventFilter.h"
#include <QMouseEvent>

KeybindEventFilter::KeybindEventFilter(QLineEdit *lineEdit, QObject *parent)
    : QObject(parent), lineEdit(lineEdit)
{
    lineEdit->installEventFilter(this);
}

bool KeybindEventFilter::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == lineEdit && event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        QString keyText = QKeySequence(keyEvent->key() | keyEvent->modifiers()).toString();
        lineEdit->setText(keyText);
        emit keySequenceChanged(keyText);
        return true;
    } else if (obj == lineEdit && event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
        QString button;
        switch (mouseEvent->button()) {
            case Qt::LeftButton: button = "LeftMouse"; break;
            case Qt::RightButton: button = "RightMouse"; break;
            case Qt::MiddleButton: button = "MiddleMouse"; break;
            case Qt::XButton1: button = "Mouse4"; break;
            case Qt::XButton2: button = "Mouse5"; break;
            default: return QObject::eventFilter(obj, event);
        }
        lineEdit->setText(button);
        emit keySequenceChanged(button);
        return true;
    }
    return QObject::eventFilter(obj, event);
}
