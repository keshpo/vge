#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include <QtSvg>
#include <QImage>

class RenderArea : public QGraphicsView
{
    Q_OBJECT
public:
    explicit RenderArea(QWidget *parent = 0);
    
    void openFile(QFile &svgFile);

signals:
    
public slots:
    void saveFile();
    void setPenSize(int pen);

    void Ellipse();
    void Square();
    void Line();
    void Polygon();
    void Rhomb();


protected:
    // void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private:




    bool setpoint;
    int penSize;
    int figure;
    int firstPointX;
    int firstPointY;
    QPoint firstPoint;
    QGraphicsScene *graphicsScene;

};

#endif // RENDERAREA_H
