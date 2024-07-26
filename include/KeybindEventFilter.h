#ifndef KEYBINDEVENTFILTER_H
#define KEYBINDEVENTFILTER_H

#include <QObject>
#include <QKeyEvent>
#include <QLineEdit>

class KeybindEventFilter : public QObject
{
    Q_OBJECT

public:
    explicit KeybindEventFilter(QLineEdit *lineEdit, QObject *parent = nullptr);

signals:
    void keySequenceChanged(const QString &keySequence);

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

private:
    QLineEdit *lineEdit;
};

#endif // KEYBINDEVENTFILTER_H
