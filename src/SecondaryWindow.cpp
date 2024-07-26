#include "SecondaryWindow.h"

SecondaryWindow::SecondaryWindow(QWidget *parent)
    : QWidget(parent)
{
    connect(this, &SecondaryWindow::shown, this, &SecondaryWindow::onLoad);
}

SecondaryWindow::~SecondaryWindow()
{
}

void SecondaryWindow::showEvent(QShowEvent *event)
{
    QWidget::showEvent(event);
    emit shown();
}

void SecondaryWindow::onLoad()
{
    // Implement the logic that needs to be executed when the secondary window is shown
}
