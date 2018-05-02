#include "padeditor.h"
#include "ui_padeditor.h"
#include "Graphics/Model/Mesh.h"

PADEditor::PADEditor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PADEditor)
{
    ui->setupUi(this);
    setCentralWidget(ui->dockWidget);
    setDockNestingEnabled(true);
}

PADEditor::~PADEditor()
{
    delete ui;
}
