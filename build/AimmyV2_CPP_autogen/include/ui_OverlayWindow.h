/********************************************************************************
** Form generated from reading UI file 'OverlayWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OVERLAYWINDOW_H
#define UI_OVERLAYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OverlayWindow
{
public:

    void setupUi(QWidget *OverlayWindow)
    {
        if (OverlayWindow->objectName().isEmpty())
            OverlayWindow->setObjectName("OverlayWindow");
        OverlayWindow->resize(400, 300);

        retranslateUi(OverlayWindow);

        QMetaObject::connectSlotsByName(OverlayWindow);
    } // setupUi

    void retranslateUi(QWidget *OverlayWindow)
    {
        OverlayWindow->setWindowTitle(QCoreApplication::translate("OverlayWindow", "OverlayWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OverlayWindow: public Ui_OverlayWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OVERLAYWINDOW_H
