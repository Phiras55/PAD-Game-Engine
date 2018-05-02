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
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QOpenGLWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PADEditor
{
public:
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QGridLayout *gridLayout;
    QOpenGLWidget *openGLWidget;
    QDockWidget *dockWidget_2;
    QWidget *dockWidgetContents_2;
    QDockWidget *dockWidget_3;
    QWidget *dockWidgetContents_3;
    QDockWidget *dockWidget_4;
    QWidget *dockWidgetContents_4;
    QDockWidget *dockWidget_5;
    QWidget *dockWidgetContents_5;

    void setupUi(QMainWindow *PADEditor)
    {
        if (PADEditor->objectName().isEmpty())
            PADEditor->setObjectName(QStringLiteral("PADEditor"));
        PADEditor->resize(1280, 720);
        PADEditor->setMinimumSize(QSize(720, 480));
        PADEditor->setMaximumSize(QSize(1920, 1080));
        centralWidget = new QWidget(PADEditor);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        PADEditor->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(PADEditor);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1280, 21));
        PADEditor->setMenuBar(menuBar);
        mainToolBar = new QToolBar(PADEditor);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        PADEditor->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(PADEditor);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        PADEditor->setStatusBar(statusBar);
        dockWidget = new QDockWidget(PADEditor);
        dockWidget->setObjectName(QStringLiteral("dockWidget"));
        dockWidget->setFeatures(QDockWidget::NoDockWidgetFeatures);
        dockWidget->setAllowedAreas(Qt::NoDockWidgetArea);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        gridLayout = new QGridLayout(dockWidgetContents);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        openGLWidget = new QOpenGLWidget(dockWidgetContents);
        openGLWidget->setObjectName(QStringLiteral("openGLWidget"));
        openGLWidget->setEnabled(true);

        gridLayout->addWidget(openGLWidget, 0, 0, 1, 1);

        dockWidget->setWidget(dockWidgetContents);
        PADEditor->addDockWidget(static_cast<Qt::DockWidgetArea>(4), dockWidget);
        dockWidget_2 = new QDockWidget(PADEditor);
        dockWidget_2->setObjectName(QStringLiteral("dockWidget_2"));
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QStringLiteral("dockWidgetContents_2"));
        dockWidget_2->setWidget(dockWidgetContents_2);
        PADEditor->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget_2);
        dockWidget_3 = new QDockWidget(PADEditor);
        dockWidget_3->setObjectName(QStringLiteral("dockWidget_3"));
        dockWidgetContents_3 = new QWidget();
        dockWidgetContents_3->setObjectName(QStringLiteral("dockWidgetContents_3"));
        dockWidget_3->setWidget(dockWidgetContents_3);
        PADEditor->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dockWidget_3);
        dockWidget_4 = new QDockWidget(PADEditor);
        dockWidget_4->setObjectName(QStringLiteral("dockWidget_4"));
        dockWidget_4->setFeatures(QDockWidget::AllDockWidgetFeatures);
        dockWidget_4->setAllowedAreas(Qt::AllDockWidgetAreas);
        dockWidgetContents_4 = new QWidget();
        dockWidgetContents_4->setObjectName(QStringLiteral("dockWidgetContents_4"));
        dockWidget_4->setWidget(dockWidgetContents_4);
        PADEditor->addDockWidget(static_cast<Qt::DockWidgetArea>(8), dockWidget_4);
        dockWidget_5 = new QDockWidget(PADEditor);
        dockWidget_5->setObjectName(QStringLiteral("dockWidget_5"));
        dockWidgetContents_5 = new QWidget();
        dockWidgetContents_5->setObjectName(QStringLiteral("dockWidgetContents_5"));
        dockWidget_5->setWidget(dockWidgetContents_5);
        PADEditor->addDockWidget(static_cast<Qt::DockWidgetArea>(8), dockWidget_5);

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
