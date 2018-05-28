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

void PADObjectWidget::on_nameEdit_textEdited(const QString &arg1)
{
    emit updated();
}
