#include "padeditor.h"
#include "ui_padeditor.h"
#include "Graphics/Model/Mesh.h"
#include "sceneview.h"
#include <QTimer>
#include <PAD Engine/Core/EngineDLL.h>
#include <PAD Engine/System/ECS/PADObject.h>

#include <Math/Transform.h>

#include "ui_padobjectwidget.h"
#include "ui_transformwidget.h"
#include <Math/Vector4.h>

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
   // ui->projectListView->

    ui->projectTreeView->setColumnHidden(1, true);
    ui->projectTreeView->setColumnHidden(2, true);
    ui->projectTreeView->setColumnHidden(3, true);
    ui->projectTreeView->header()->hide();

//Inspector
    padWidget = new PADObjectWidget();
    transformWidget = new TransformWidget();

    ui->InspecContent->layout()->addWidget(padWidget);
    ui->InspecContent->layout()->addWidget(transformWidget);


//Hierarchy
    sceneView = new SceneView(ui->Hierarchy_Content);
    ui->Hierarchy_Content->layout()->addWidget(sceneView);

    connect(sceneView, SIGNAL(itemSelectionChanged()), this, SLOT(updateInspector()));

    connect(padWidget, SIGNAL(updated()), this, SLOT(UpdateCurrentItem()));
    connect(transformWidget, SIGNAL(updated()), this, SLOT(UpdateCurrentItem()));


//FocusPolicy
    setContextMenuPolicy(Qt::ContextMenuPolicy::PreventContextMenu);
    openGLWidget->setFocusPolicy(Qt::FocusPolicy::ClickFocus);
}

PADEditor::~PADEditor()
{
    delete ui;
}

void PADEditor::PostEngineInit()
{
    sceneView->ParseScene();
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

void PADEditor::updateInspector()
{
    padWidget->ui->nameEdit->setText(sceneView->currentObject->GetName().c_str());

    transformWidget->ui->val_Pos_X->setValue(sceneView->currentObject->GetTransform().Position().x);
    transformWidget->ui->val_Pos_Y->setValue(sceneView->currentObject->GetTransform().Position().y);
    transformWidget->ui->val_Pos_Z->setValue(sceneView->currentObject->GetTransform().Position().z);

    transformWidget->ui->val_Rot_X->setValue(sceneView->currentObject->GetTransform().Rotation().x);
    transformWidget->ui->val_Rot_Y->setValue(sceneView->currentObject->GetTransform().Rotation().y);
    transformWidget->ui->val_Rot_Z->setValue(sceneView->currentObject->GetTransform().Rotation().z);

    transformWidget->ui->val_Scale_X->setValue(sceneView->currentObject->GetTransform().Scale().x);
    transformWidget->ui->val_Scale_Y->setValue(sceneView->currentObject->GetTransform().Scale().y);
    transformWidget->ui->val_Scale_Z->setValue(sceneView->currentObject->GetTransform().Scale().z);

}

void PADEditor::UpdateCurrentItem()
{
    sceneView->currentObject->SetName(padWidget->ui->nameEdit->text().toLatin1().constData());

    pad::math::Vec3f pos(   transformWidget->ui->val_Pos_X->value(),
                            transformWidget->ui->val_Pos_Y->value(),
                            transformWidget->ui->val_Pos_Z->value());

    pad::math::Vec3f rot(   transformWidget->ui->val_Rot_X->value(),
                            transformWidget->ui->val_Rot_Y->value(),
                            transformWidget->ui->val_Rot_Z->value());

    pad::math::Vec3f scale( transformWidget->ui->val_Scale_X->value(),
                            transformWidget->ui->val_Scale_Y->value(),
                            transformWidget->ui->val_Scale_Z->value());

    sceneView->currentObject->GetTransform().SetPosition(pos);
    sceneView->currentObject->GetTransform().SetRotation(rot);
    sceneView->currentObject->GetTransform().SetScale(scale);

}
