#ifndef UNIT_H
#define UNIT_H

#include <QObject>
#include "QGraphicsRectItem"

class Unit : public QObject
{
    Q_OBJECT
    int sleepTime = 100; // ms of delay

    int value_; //main thing of this  class


public:

    //  the rectangle in the graphicsScene which represents the value of this object
    QGraphicsRectItem* column_rect;
    QGraphicsTextItem* column_value;
    Unit();
    ~Unit() {}
    Unit(Unit&&);
    Unit& operator=(Unit&&);
    Unit& operator=(int);
    bool operator<(const Unit&);
    operator int(){ return value_; }
    void set_columnRect(QGraphicsRectItem* columnRect) { column_rect = columnRect; }
    void set_columnV(QGraphicsTextItem* columnV) {  column_value = columnV; }
    QGraphicsRectItem* get_columnRect() const { return column_rect; }
    QGraphicsTextItem* get_columnV() const { return column_value; }

signals:
    void operatorCOMP(QGraphicsRectItem* item1, QGraphicsRectItem* item2); //when we compare RED
    void operatorEQ(QGraphicsRectItem* item,  QGraphicsTextItem* text, float val); //when we change value GREEN
};

#endif // UNIT_H