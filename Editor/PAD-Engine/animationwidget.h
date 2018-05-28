#ifndef ANIMATIONWIDGET_H
#define ANIMATIONWIDGET_H

#include <QWidget>

namespace Ui {
class AnimationWidget;
}

class AnimationWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AnimationWidget(QWidget *parent = 0);
    ~AnimationWidget();

Q_SIGNALS:
    void updated();

private slots:
    void on_meshEdit_editingFinished();
    void on_materialEdit_editingFinished();
    void on_animEdit_editingFinished();
    void on_skeletonEdit_editingFinished();

    void on_speedEdit_editingFinished();

    void on_Loop_stateChanged(int arg1);

public:
    Ui::AnimationWidget *ui;
};

#endif // ANIMATIONWIDGET_H
