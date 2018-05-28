#ifndef PADOBJECTWIDGET_H
#define PADOBJECTWIDGET_H

#include <QWidget>
#include <PAD Engine/System/ECS/PADObject.h>

namespace Ui {
class PADObjectWidget;
}

class PADObjectWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PADObjectWidget(QWidget *parent = 0);
    ~PADObjectWidget();

    Ui::PADObjectWidget *ui;
private slots:
    void on_nameEdit_textEdited(const QString &arg1);

Q_SIGNALS:
    void updated();

};

#endif // PADOBJECTWIDGET_H
