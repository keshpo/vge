#include "window.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Window w;
    if (argc == 2){//argc - количество аргументов запуска
        //какие то действия, если открываем файл перетаскиванием на экзешник
    }




    w.show();









    //QSvgWidget svg(":/Svg.svg");
    //svg.show();
    //QObject::connect(svg.renderer(), SIGNAL(repaintNeeded()), &svg, SLOT(repaint()));
    
    return a.exec();
}
