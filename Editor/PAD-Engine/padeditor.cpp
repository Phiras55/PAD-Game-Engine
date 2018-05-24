#include "padeditor.h"
#include "transformwidget.h"
#include "padobjectwidget.h"
#include "ui_padeditor.h"
#include "Graphics/Model/Mesh.h"
#include "sceneview.h"
#include <QTimer>
#include <PAD Engine/Core/EngineDLL.h>
#include <PAD Engine/System/ECS/PADObject.h>


PADEditor::PADEditor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PADEditor)
{
    ui->setupUi(this);
//GLWidget
    openGLWidget = new GLWidget(0);
    openGLWidget->Init();
    ui->OpenGL_Content->layout()->addWidget(openGLWidget);
    setCentralWidget(ui->OpenGl);
    setDockNestingEnabled(true);

//File system
    QString contentPath = "Resources";
    DirModel = new QFileSystemModel(this);
    DirModel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
    DirModel->setRootPath(contentPath);
    ui->projectTreeView->setModel(DirModel);
    ui->projectTreeView->setRootIndex(DirModel->setRootPath(contentPath));

    FileModel = new QFileSystemModel(this);
    FileModel->setFilter(QDir::NoDotAndDotDot | QDir::Files);
    FileModel->setRootPath(contentPath);
    ui->projectListView->setModel(FileModel);
    ui->projectListView->setRootIndex(FileModel->setRootPath(contentPath));

    ui->projectTreeView->setColumnHidden(1, true);
    ui->projectTreeView->setColumnHidden(2, true);
    ui->projectTreeView->setColumnHidden(3, true);
    ui->projectTreeView->header()->hide();

//Inspector
    ui->InspecContent->layout()->addWidget(new PADObjectWidget());
    ui->InspecContent->layout()->addWidget(new TransformWidget());


//Hierarchy
    sceneView = new SceneView(ui->Hierarchy_Content);
    ui->Hierarchy_Content->layout()->addWidget(sceneView);

//FocusPolicy
    setContextMenuPolicy(Qt::ContextMenuPolicy::PreventContextMenu);
    openGLWidget->setFocusPolicy(Qt::FocusPolicy::ClickFocus);
}

PADEditor::~PADEditor()
{
    delete ui;
}

void PADEditor::on_projectTreeView_clicked(const QModelIndex &index)
{
    ui->projectListView->setRootIndex(FileModel->setRootPath(DirModel->fileInfo(index).absoluteFilePath()));
}

void PADEditor::on_projectListView_doubleClicked(const QModelIndex &index)
{
    QString currentPath = FileModel->fileInfo(index).absoluteFilePath();
    ui->projectListView->setRootIndex(FileModel->setRootPath(currentPath));
}

void PADEditor::on_actionAdd_Pad_Object_triggered()
{
    pad::sys::ecs::PADObject* obj = pad::CreatePADObject("DefaultName", nullptr);
    sceneView->AddObject(obj, nullptr);
}
