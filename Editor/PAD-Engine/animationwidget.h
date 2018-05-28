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

private slots:
    void on_AnimationWidget_customContextMenuRequested(const QPoint &pos);

private:
    Ui::AnimationWidget *ui;
};

#endif // ANIMATIONWIDGET_H
