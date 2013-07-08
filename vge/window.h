#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QWidget>

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
    
private:
    Ui::Window *ui;
};

#endif // WINDOW_H
