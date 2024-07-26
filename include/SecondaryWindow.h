#ifndef SECONDARYWINDOW_H
#define SECONDARYWINDOW_H

#include <QWidget>
#include <QShowEvent>

class SecondaryWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SecondaryWindow(QWidget *parent = nullptr);
    ~SecondaryWindow();

signals:
    void shown();

protected:
    void showEvent(QShowEvent *event) override;

private slots:
    void onLoad();
};

#endif // SECONDARYWINDOW_H
