#include "padeditor.h"
#include "ui_padeditor.h"
#include "Graphics/Model/Mesh.h"
#include <QTimer>

#include <glwidget.h>

PADEditor::PADEditor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PADEditor)
{
    ui->setupUi(this);

    GLWidget* openGLWidget = new GLWidget(0);
    ui->dockWidgetContents->layout()->addWidget(openGLWidget);
    setCentralWidget(ui->OpenGl);
    setDockNestingEnabled(true);

    openGLWidget->setFocusPolicy(Qt::FocusPolicy::ClickFocus);
}

PADEditor::~PADEditor()
{
    delete ui;
}
