#ifndef TRANSFORMWIDGET_H
#define TRANSFORMWIDGET_H

#include <QWidget>

namespace Ui {
class TransformWidget;
}

class TransformWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TransformWidget(QWidget *parent = 0);
    ~TransformWidget();

    Ui::TransformWidget *ui;
private slots:
    void on_val_Pos_X_editingFinished();
    void on_val_Pos_Y_editingFinished();
    void on_val_Pos_Z_editingFinished();

    void on_val_Rot_X_editingFinished();
    void on_val_Rot_Y_editingFinished();
    void on_val_Rot_Z_editingFinished();

    void on_val_Scale_X_editingFinished();
    void on_val_Scale_Y_editingFinished();
    void on_val_Scale_Z_editingFinished();

Q_SIGNALS:
    void updated();
};

#endif // TRANSFORMWIDGET_H
