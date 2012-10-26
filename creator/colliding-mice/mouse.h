#ifndef MOUSE_H
#define MOUSE_H
#include <QGraphicsItem>
#include "AllClasses.h"

class Particle : public QGraphicsItem
{
public:
    Particle(QColor colour);

    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);

    Particle();
    Particle(double mass , Vector velocity  , Vector acceleration , double radius , Vector position);
    Vector getPosition();
    void move(double t);
    Vector getVelocity();
    void updateVelocity(Vector velocity);
    void updateAcceleration(Vector acceleration);
    void updatePosition(Vector point);
        //	void addCoordinates(Vector point);

    Vector getAcceleration();
    double getRadius();


protected:
    void advance(int step);

private:
    qreal angle;
    qreal speed;
    qreal mouseEyeDirection;
    QColor color;
    double _mass;
    Vector _position;
    Vector _velocity;
    Vector _acceleration;
    double _radius;

};

#endif // MOUSE_H
