#include "transformwidget.h"
#include "ui_transformwidget.h"

TransformWidget::TransformWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TransformWidget)
{
    ui->setupUi(this);
}

TransformWidget::~TransformWidget()
{
    delete ui;
}

void TransformWidget::on_val_Pos_X_valueChanged(double arg1){   emit updated(); }
void TransformWidget::on_val_Pos_Y_valueChanged(double arg1){   emit updated(); }
void TransformWidget::on_val_Pos_Z_valueChanged(double arg1){   emit updated(); }
void TransformWidget::on_val_Rot_X_valueChanged(double arg1){   emit updated(); }
void TransformWidget::on_val_Rot_Y_valueChanged(double arg1){   emit updated(); }
void TransformWidget::on_val_Rot_Z_valueChanged(double arg1){   emit updated(); }
void TransformWidget::on_val_Scale_X_valueChanged(double arg1){ emit updated(); }
void TransformWidget::on_val_Scale_Y_valueChanged(double arg1){ emit updated(); }
void TransformWidget::on_val_Scale_Z_valueChanged(double arg1){ emit updated(); }
