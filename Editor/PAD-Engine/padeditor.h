#ifndef PADEDITOR_H
#define PADEDITOR_H

#include <QtWidgets/QMainWindow>

namespace Ui {
class PADEditor;
}

class PADEditor : public QMainWindow
{
    //Q_OBJECT

public:
    explicit PADEditor(QWidget *parent = 0);
    ~PADEditor();

private:
    Ui::PADEditor *ui;
};

#endif // PADEDITOR_H
