#ifndef OVERLAYWINDOW_H
#define OVERLAYWINDOW_H

#include <QWidget>
#include <QShowEvent>

class OverlayWindow : public QWidget
{
    Q_OBJECT

public:
    explicit OverlayWindow(QWidget *parent = nullptr);
    ~OverlayWindow();

signals:
    void shown();

protected:
    void showEvent(QShowEvent *event) override;

private slots:
    void onOverlayLoad();
};

#endif // OVERLAYWINDOW_H
