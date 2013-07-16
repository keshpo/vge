#include "renderarea.h"

RenderArea::RenderArea(QWidget *parent) :
    QGraphicsView(parent)
{
    figure = 0;
    setpoint = false;
    setScene(new QGraphicsScene(this));
    setTransformationAnchor(AnchorUnderMouse);//
    setDragMode(NoDrag);//перемещение
    setViewportUpdateMode(FullViewportUpdate);//

    QPixmap tilePixmap(64, 64);
    tilePixmap.fill(Qt::white);
    QPainter tilePainter(&tilePixmap);
    QColor color(220, 220, 220);
    tilePainter.fillRect(0, 0, 32, 32, color);
    tilePainter.fillRect(32, 32, 32, 32, color);
    tilePainter.end();

    setBackgroundBrush(tilePixmap);
    graphicsScene = scene();
}
void RenderArea::openFile(QFile &svgFile)
{
    graphicsScene->clear();
    resetTransform();

    QGraphicsItem *loadItem;
    loadItem = new QGraphicsSvgItem(svgFile.fileName());
    graphicsScene->addItem(loadItem);
}

void RenderArea::setPenSize(int pen)
{
    penSize = pen;
}

void RenderArea::Ellipse()
{
    figure = 0;
}

void RenderArea::Square()
{
    figure = 1;
}

void RenderArea::Line()
{
    figure = 2;
}

void RenderArea::Polygon()
{
    figure = 3;
}

void RenderArea::Rhomb()
{
    figure = 4;
}

void RenderArea::saveFile()
{
    QString savePath = QFileDialog::getSaveFileName(this, "Save file", "", "SVG files (*.svg)");

    if (savePath.isEmpty())
        return;

    /*QSvgGenerator generator;
    generator.setFileName(savePath);
    generator.setSize(RenderArea::size());
    generator.setViewBox(QRect(QPoint(0,0), RenderArea::size()) );*/



}



void RenderArea::mousePressEvent(QMouseEvent *event)
{
    if ((event->button() == Qt::LeftButton) && (!setpoint)) {
        qDebug() << event->pos();
        firstPointX = event->x();
        firstPointY = event->y();
        //firstPoint = event->pos();
        setpoint = true;
    }
}

void RenderArea::mouseMoveEvent(QMouseEvent *event)
{
    if ((event->buttons() == Qt::LeftButton) && setpoint){

        //QGraphicsItem *newItem;
        //newItem = new QGraphicsLineItem(0,0,20,20,0);
        //newItem = new QGraphicsItem(newitem);
        //graphicsScene->addItem(newItem);

    }
}

void RenderArea::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && setpoint) {

        QGraphicsItem *newItem;
        newItem = new QGraphicsLineItem(firstPointX,firstPointY,0,0,0);
        //newItem = new QGraphicsItem();
        graphicsScene->addItem(newItem);
        //drawLineTo(event->pos());
        setpoint = false;

    }
}
