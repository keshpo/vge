#include "colors.h"

ColorWidget::ColorWidget(QColor qColor, QWidget *parent) :
    QLabel(parent)
{
    setFrameStyle(QFrame::Raised | QFrame::Box);
    color = new QColor;
    *color = qColor;

    wgtPixmap = new QPixmap(20, 20);
    wgtPainter = new QPainter(wgtPixmap);
    wgtPainter->fillRect(0, 0, 20, 20, *color);
    wgtPainter->end();

    setMargin(3);
    setAlignment(Qt::AlignHCenter);
    setPixmap(*wgtPixmap);
}

void ColorWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {

        QColor tmpColor = QColorDialog::getColor(*color,this,"Color",0);
        if(tmpColor.isValid())
        {
            *color = tmpColor;
            wgtPainter->begin(wgtPixmap);
            wgtPainter->fillRect(0, 0, 20, 20, *color);
            wgtPainter->end();
            setPixmap(*wgtPixmap);
            //emit sendColor(color);

        }
    }
}
