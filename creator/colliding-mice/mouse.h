#ifndef MOUSE_H
#define MOUSE_H
#include <QGraphicsItem>
#include "AllClasses.h"


#define Xleft -150
#define Xright 150
#define Ytop 150
#define Ybottom -150



//#define particleMass 1
//#define particleRadius 1

class Particle : public QGraphicsItem
{

private:
    qreal angle;
    qreal mouseEyeDirection;
    QColor color;
    double _mass;
    Vector _position;
    Vector _nextPosition;
    Vector _velocity;
    Vector _acceleration;
    double _radius;




public:
    Particle(QColor colour,double mass , double Radius);
    //Particle(QColor colour,double mass , double Radius ,Vector Velocity);

    Particle();
    Particle(double mass , Vector velocity  , Vector acceleration , double Radius , Vector position);

    void set_pos();

    \

    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);

    Vector getPosition();
    double getMass();
    void move(double t);
    Vector getVelocity();
    void updateVelocity(Vector velocity);
    void updateAcceleration(Vector acceleration);
    void updatePosition();
        //	void addCoordinates(Vector point);

    Vector getAcceleration();
    double getRadius();
    //void operator =(Particle P);


protected:
    void advance(int step);


};

#endif // MOUSE_H
