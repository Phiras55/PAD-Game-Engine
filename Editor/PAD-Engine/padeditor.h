#ifndef PADEDITOR_H
#define PADEDITOR_H

#include <QMainWindow>
#include <QFileSystemModel>

namespace Ui {
class PADEditor;
}

class PADEditor : public QMainWindow
{

    Q_OBJECT

public:
    explicit PADEditor(QWidget *parent = 0);
    ~PADEditor();

private slots:
    void on_projectTreeView_clicked(const QModelIndex &index);
    void on_projectListView_doubleClicked(const QModelIndex &index);

    void on_actionAdd_Transform_triggered();

private:
    Ui::PADEditor *ui;

    QFileSystemModel* DirModel;
    QFileSystemModel* FileModel;
};

#endif // PADEDITOR_H
