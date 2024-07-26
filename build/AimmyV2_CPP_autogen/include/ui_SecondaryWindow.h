/********************************************************************************
** Form generated from reading UI file 'SecondaryWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECONDARYWINDOW_H
#define UI_SECONDARYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SecondaryWindow
{
public:

    void setupUi(QWidget *SecondaryWindow)
    {
        if (SecondaryWindow->objectName().isEmpty())
            SecondaryWindow->setObjectName("SecondaryWindow");
        SecondaryWindow->resize(400, 300);

        retranslateUi(SecondaryWindow);

        QMetaObject::connectSlotsByName(SecondaryWindow);
    } // setupUi

    void retranslateUi(QWidget *SecondaryWindow)
    {
        SecondaryWindow->setWindowTitle(QCoreApplication::translate("SecondaryWindow", "SecondaryWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SecondaryWindow: public Ui_SecondaryWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECONDARYWINDOW_H
