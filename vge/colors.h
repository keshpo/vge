#ifndef COLORS_H
#define COLORS_H

#include <QLabel>
#include <QFrame>
#include <QMouseEvent>
#include <QtWidgets>

class ColorWidget : public QLabel
{
    Q_OBJECT
public:
    explicit ColorWidget(QColor qColor, QWidget *parent = 0);
    
signals:
    
public slots:

protected:
    void mousePressEvent(QMouseEvent *event);

private:
    QColor *color;
    QPainter *wgtPainter;
    QPixmap *wgtPixmap;
    
};

#endif // COLORS_H
