/********************************************************************************
** Form generated from reading UI file 'animationwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANIMATIONWIDGET_H
#define UI_ANIMATIONWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AnimationWidget
{
public:

    void setupUi(QWidget *AnimationWidget)
    {
        if (AnimationWidget->objectName().isEmpty())
            AnimationWidget->setObjectName(QStringLiteral("AnimationWidget"));
        AnimationWidget->resize(400, 300);

        retranslateUi(AnimationWidget);

        QMetaObject::connectSlotsByName(AnimationWidget);
    } // setupUi

    void retranslateUi(QWidget *AnimationWidget)
    {
        AnimationWidget->setWindowTitle(QApplication::translate("AnimationWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AnimationWidget: public Ui_AnimationWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANIMATIONWIDGET_H
