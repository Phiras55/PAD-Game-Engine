#include "boxcolliderwidget.h"
#include "ui_boxcolliderwidget.h"

BoxColliderWidget::BoxColliderWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BoxColliderWidget)
{
    ui->setupUi(this);
}

BoxColliderWidget::~BoxColliderWidget()
{
    delete ui;
}
