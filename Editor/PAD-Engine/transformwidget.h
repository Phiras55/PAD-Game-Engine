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
    void on_val_Pos_X_valueChanged(double arg1);
    void on_val_Pos_Y_valueChanged(double arg1);
    void on_val_Pos_Z_valueChanged(double arg1);

    void on_val_Rot_X_valueChanged(double arg1);
    void on_val_Rot_Y_valueChanged(double arg1);
    void on_val_Rot_Z_valueChanged(double arg1);

    void on_val_Scale_X_valueChanged(double arg1);
    void on_val_Scale_Y_valueChanged(double arg1);
    void on_val_Scale_Z_valueChanged(double arg1);

Q_SIGNALS:
    void updated();
};

#endif // TRANSFORMWIDGET_H
