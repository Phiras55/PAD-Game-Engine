#ifndef MESHWIDGET_H
#define MESHWIDGET_H

#include <QWidget>

namespace Ui {
class MeshWidget;
}

class MeshWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MeshWidget(QWidget *parent = 0);
    ~MeshWidget();

Q_SIGNALS:
    void updated();

private slots:
    void on_meshEdit_editingFinished();
    void on_materialEdit_editingFinished();

public:
    Ui::MeshWidget *ui;
};

#endif // MESHWIDGET_H
