#ifndef PADOBJECTWIDGET_H
#define PADOBJECTWIDGET_H

#include <QWidget>

namespace Ui {
class PADObjectWidget;
}

class PADObjectWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PADObjectWidget(QWidget *parent = 0);
    ~PADObjectWidget();

private:
    Ui::PADObjectWidget *ui;
};

#endif // PADOBJECTWIDGET_H
