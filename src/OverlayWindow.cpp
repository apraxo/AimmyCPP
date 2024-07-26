#include "OverlayWindow.h"

OverlayWindow::OverlayWindow(QWidget *parent)
    : QWidget(parent)
{
    connect(this, &OverlayWindow::shown, this, &OverlayWindow::onOverlayLoad);
}

OverlayWindow::~OverlayWindow()
{
}

void OverlayWindow::showEvent(QShowEvent *event)
{
    QWidget::showEvent(event);
    emit shown();
}

void OverlayWindow::onOverlayLoad()
{
    // Implement the logic that needs to be executed when the overlay is shown
}
