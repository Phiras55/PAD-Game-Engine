/********************************************************************************
** Form generated from reading UI file 'boxcolliderwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOXCOLLIDERWIDGET_H
#define UI_BOXCOLLIDERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BoxColliderWidget
{
public:

    void setupUi(QWidget *BoxColliderWidget)
    {
        if (BoxColliderWidget->objectName().isEmpty())
            BoxColliderWidget->setObjectName(QStringLiteral("BoxColliderWidget"));
        BoxColliderWidget->resize(400, 300);

        retranslateUi(BoxColliderWidget);

        QMetaObject::connectSlotsByName(BoxColliderWidget);
    } // setupUi

    void retranslateUi(QWidget *BoxColliderWidget)
    {
        BoxColliderWidget->setWindowTitle(QApplication::translate("BoxColliderWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BoxColliderWidget: public Ui_BoxColliderWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOXCOLLIDERWIDGET_H
