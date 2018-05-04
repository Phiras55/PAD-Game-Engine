#include "padeditor.h"
#include "ui_padeditor.h"
#include "Graphics/Model/Mesh.h"
#include <QTimer>

PADEditor::PADEditor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PADEditor)
{
    ui->setupUi(this);
    setCentralWidget(ui->dockWidget);
    setDockNestingEnabled(true);
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), ui->openGLWidget, SLOT(ui->openGLWidget->PaintGL()));
    timer->start();
    ui->openGLWidget->setFocusPolicy(Qt::FocusPolicy::ClickFocus);

}

PADEditor::~PADEditor()
{
    delete ui;
}
