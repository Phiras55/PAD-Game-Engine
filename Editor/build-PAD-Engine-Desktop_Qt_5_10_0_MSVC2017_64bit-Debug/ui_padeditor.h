/********************************************************************************
** Form generated from reading UI file 'padeditor.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PADEDITOR_H
#define UI_PADEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PADEditor
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *PADEditor)
    {
        if (PADEditor->objectName().isEmpty())
            PADEditor->setObjectName(QStringLiteral("PADEditor"));
        PADEditor->resize(400, 300);
        menuBar = new QMenuBar(PADEditor);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        PADEditor->setMenuBar(menuBar);
        mainToolBar = new QToolBar(PADEditor);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        PADEditor->addToolBar(mainToolBar);
        centralWidget = new QWidget(PADEditor);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        PADEditor->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(PADEditor);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        PADEditor->setStatusBar(statusBar);

        retranslateUi(PADEditor);

        QMetaObject::connectSlotsByName(PADEditor);
    } // setupUi

    void retranslateUi(QMainWindow *PADEditor)
    {
        PADEditor->setWindowTitle(QApplication::translate("PADEditor", "PADEditor", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PADEditor: public Ui_PADEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PADEDITOR_H
