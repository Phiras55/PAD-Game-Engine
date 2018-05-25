#include "padobjectwidget.h"
#include "ui_padobjectwidget.h"

PADObjectWidget::PADObjectWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PADObjectWidget)
{
    ui->setupUi(this);

}

PADObjectWidget::~PADObjectWidget()
{
    delete ui;
}
