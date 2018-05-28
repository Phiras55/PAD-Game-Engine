#include "animationwidget.h"
#include "ui_animationwidget.h"

AnimationWidget::AnimationWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AnimationWidget)
{
    ui->setupUi(this);
}

AnimationWidget::~AnimationWidget()
{
    delete ui;
}


void AnimationWidget::on_meshEdit_editingFinished()         { emit updated(); }
void AnimationWidget::on_materialEdit_editingFinished()     { emit updated(); }
void AnimationWidget::on_animEdit_editingFinished()         { emit updated(); }
void AnimationWidget::on_skeletonEdit_editingFinished()     { emit updated(); }
void AnimationWidget::on_speedEdit_editingFinished()        { emit updated(); }
void AnimationWidget::on_Loop_stateChanged(int arg1)        { emit updated(); }
