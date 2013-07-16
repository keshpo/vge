#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QtWidgets>
#include <renderarea.h>
#include <colors.h>

namespace Ui {
class Window;
}

class Window : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Window(QWidget *parent = 0);
    ~Window();

public slots:
    void openFile(const QString &path = QString());
    //void saveFile();

private slots:
    void createFile();
    void aboutVge();
    void setColor();
private:

    RenderArea *area;
    QScrollArea *scrollArea;
    ColorWidget *firstColorWidget;
    ColorWidget *secondColorWidget;
    QColor *firstColor;
    QColor *secondColor;
    //QPixmap *colorIcon;
    //QColor *color;
    //QAction *colorSelect;
};

#endif // WINDOW_H
