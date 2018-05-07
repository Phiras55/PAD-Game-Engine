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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PADEditor
{
public:
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuView;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *OpenGl;
    QWidget *OpenGL_Content;
    QGridLayout *gridLayout;
    QDockWidget *Hierarchy;
    QWidget *Hierarchy_Content;
    QGridLayout *gridLayout_4;
    QTreeView *hierarchyTreeView;
    QDockWidget *Inspector;
    QWidget *Inspector_Content;
    QGridLayout *gridLayout_3;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QFormLayout *formLayout;
    QDockWidget *Project_View;
    QWidget *Project_View_Content;
    QGridLayout *gridLayout_2;
    QSplitter *splitter;
    QTreeView *projectTreeView;
    QListView *projectListView;
    QDockWidget *Console;
    QWidget *Console_Content;
    QGridLayout *gridLayout_5;
    QPlainTextEdit *consoleOutput;

    void setupUi(QMainWindow *PADEditor)
    {
        if (PADEditor->objectName().isEmpty())
            PADEditor->setObjectName(QStringLiteral("PADEditor"));
        PADEditor->resize(1280, 720);
        PADEditor->setMinimumSize(QSize(720, 480));
        PADEditor->setStyleSheet(QStringLiteral(""));
        PADEditor->setDockNestingEnabled(false);
        centralWidget = new QWidget(PADEditor);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QStringLiteral(""));
        PADEditor->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(PADEditor);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1280, 20));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QStringLiteral("menuView"));
        PADEditor->setMenuBar(menuBar);
        mainToolBar = new QToolBar(PADEditor);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        PADEditor->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(PADEditor);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        PADEditor->setStatusBar(statusBar);
        OpenGl = new QDockWidget(PADEditor);
        OpenGl->setObjectName(QStringLiteral("OpenGl"));
        OpenGl->setFloating(false);
        OpenGl->setFeatures(QDockWidget::AllDockWidgetFeatures);
        OpenGl->setAllowedAreas(Qt::AllDockWidgetAreas);
        OpenGL_Content = new QWidget();
        OpenGL_Content->setObjectName(QStringLiteral("OpenGL_Content"));
        gridLayout = new QGridLayout(OpenGL_Content);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        OpenGl->setWidget(OpenGL_Content);
        PADEditor->addDockWidget(static_cast<Qt::DockWidgetArea>(4), OpenGl);
        Hierarchy = new QDockWidget(PADEditor);
        Hierarchy->setObjectName(QStringLiteral("Hierarchy"));
        Hierarchy_Content = new QWidget();
        Hierarchy_Content->setObjectName(QStringLiteral("Hierarchy_Content"));
        gridLayout_4 = new QGridLayout(Hierarchy_Content);
        gridLayout_4->setSpacing(0);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        hierarchyTreeView = new QTreeView(Hierarchy_Content);
        hierarchyTreeView->setObjectName(QStringLiteral("hierarchyTreeView"));

        gridLayout_4->addWidget(hierarchyTreeView, 0, 0, 1, 1);

        Hierarchy->setWidget(Hierarchy_Content);
        PADEditor->addDockWidget(static_cast<Qt::DockWidgetArea>(1), Hierarchy);
        Inspector = new QDockWidget(PADEditor);
        Inspector->setObjectName(QStringLiteral("Inspector"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Inspector->sizePolicy().hasHeightForWidth());
        Inspector->setSizePolicy(sizePolicy);
        Inspector_Content = new QWidget();
        Inspector_Content->setObjectName(QStringLiteral("Inspector_Content"));
        Inspector_Content->setSizeIncrement(QSize(0, 0));
        gridLayout_3 = new QGridLayout(Inspector_Content);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(Inspector_Content);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 68, 392));
        formLayout = new QFormLayout(scrollAreaWidgetContents);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_3->addWidget(scrollArea, 0, 0, 1, 1);

        Inspector->setWidget(Inspector_Content);
        PADEditor->addDockWidget(static_cast<Qt::DockWidgetArea>(2), Inspector);
        Project_View = new QDockWidget(PADEditor);
        Project_View->setObjectName(QStringLiteral("Project_View"));
        Project_View->setFeatures(QDockWidget::AllDockWidgetFeatures);
        Project_View->setAllowedAreas(Qt::AllDockWidgetAreas);
        Project_View_Content = new QWidget();
        Project_View_Content->setObjectName(QStringLiteral("Project_View_Content"));
        gridLayout_2 = new QGridLayout(Project_View_Content);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        splitter = new QSplitter(Project_View_Content);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        splitter->setHandleWidth(0);
        splitter->setChildrenCollapsible(false);
        projectTreeView = new QTreeView(splitter);
        projectTreeView->setObjectName(QStringLiteral("projectTreeView"));
        projectTreeView->setMaximumSize(QSize(200, 16777215));
        splitter->addWidget(projectTreeView);
        projectListView = new QListView(splitter);
        projectListView->setObjectName(QStringLiteral("projectListView"));
        splitter->addWidget(projectListView);

        gridLayout_2->addWidget(splitter, 0, 0, 1, 1);

        Project_View->setWidget(Project_View_Content);
        PADEditor->addDockWidget(static_cast<Qt::DockWidgetArea>(8), Project_View);
        Console = new QDockWidget(PADEditor);
        Console->setObjectName(QStringLiteral("Console"));
        Console_Content = new QWidget();
        Console_Content->setObjectName(QStringLiteral("Console_Content"));
        gridLayout_5 = new QGridLayout(Console_Content);
        gridLayout_5->setSpacing(0);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        consoleOutput = new QPlainTextEdit(Console_Content);
        consoleOutput->setObjectName(QStringLiteral("consoleOutput"));

        gridLayout_5->addWidget(consoleOutput, 0, 0, 1, 1);

        Console->setWidget(Console_Content);
        PADEditor->addDockWidget(static_cast<Qt::DockWidgetArea>(8), Console);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuView->menuAction());

        retranslateUi(PADEditor);

        QMetaObject::connectSlotsByName(PADEditor);
    } // setupUi

    void retranslateUi(QMainWindow *PADEditor)
    {
        PADEditor->setWindowTitle(QApplication::translate("PADEditor", "PADEditor", nullptr));
        menuFile->setTitle(QApplication::translate("PADEditor", "File", nullptr));
        menuEdit->setTitle(QApplication::translate("PADEditor", "Edit", nullptr));
        menuView->setTitle(QApplication::translate("PADEditor", "View", nullptr));
        OpenGl->setWindowTitle(QApplication::translate("PADEditor", "OpenGL", nullptr));
        Hierarchy->setWindowTitle(QApplication::translate("PADEditor", "Hierarchy", nullptr));
        Inspector->setWindowTitle(QApplication::translate("PADEditor", "Inspector", nullptr));
        Project_View->setWindowTitle(QApplication::translate("PADEditor", "Project", nullptr));
        Console->setWindowTitle(QApplication::translate("PADEditor", "Console", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PADEditor: public Ui_PADEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PADEDITOR_H
