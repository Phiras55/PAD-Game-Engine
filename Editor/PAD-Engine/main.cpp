#include "padeditor.h"
#include <QApplication>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PADEditor w;
    w.show();



    return a.exec();
}
