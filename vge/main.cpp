#include "window.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Window w;
    if (argc == 2){//argc - количество аргументов запуска
        w.openFile(QString(argv[2]));
    }
    w.show();
    return a.exec();
}
