#include "mouse.h"
#include<iostream>
#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>
#include <QColor>
#include <math.h>
static const double Pi = 3.14159265358979323846264338327950288419717;
static double TwoPi = 2.0 * Pi;
#define radius 10

static qreal normalizeAngle(qreal angle)
{
    while (angle < 0)
        angle += TwoPi;
    while (angle > TwoPi)
        angle -= TwoPi;
    return angle;
}

Particle::Particle(QColor colour,double mass , double Radius )
    //: angle(0), speed(0), mouseEyeDirection(0),
    //  color(qrand() % 256, qrand() % 256, qrand() % 256)
    //:color(0,0,0)
{
   // setRotation(qrand() % (360 * 16));
    //angle= (qrand()%4)*Pi/2;
    angle = Pi/4;
   // mouseEyeDirection=0;
   color = colour;
   //_velocity.x = (qrand()%100)/100;
   //_velocity.y = (qrand()%100)/100;
   _velocity.x =0;
   _velocity.y =0;
   // _velocity = velocity;
   _acceleration.x=0.000;
    _acceleration.y=0.000;
    _mass=mass;
    _radius=Radius;

   //_position.x= mapToParent( 0 ,0 ).x();
   // _position.y= mapToParent( 0 , 0).y();

    mouseEyeDirection=0.2;

}
/*
Particle::Particle(QColor colour,double mass , double Radius,Vector velocity )
    //: angle(0), speed(0), mouseEyeDirection(0),
    //  color(qrand() % 256, qrand() % 256, qrand() % 256)
    //:color(0,0,0)
{
   // setRotation(qrand() % (360 * 16));
    //angle= (qrand()%4)*Pi/2;
    angle = Pi/4;
   // mouseEyeDirection=0;
   color = colour;
    //_velocity.x = 0.1;
    //_velocity.y = 0.1;
    _velocity = velocity;
   _acceleration.x=0;
    _acceleration.y=0;
    _mass=mass;
    _radius=Radius;

   //_position.x= mapToParent( 0 ,0 ).x();
   // _position.y= mapToParent( 0 , 0).y();

    mouseEyeDirection=0.2;

}

*/

Particle::Particle()
    {
        _velocity = Vector(0.1,0.1);
        _acceleration= Vector(0,0);
    }


Particle::Particle(double mass, Vector velocity , Vector acceleration  , double Radius, Vector position)
    {
        _mass=mass;
        _velocity=velocity;
        _acceleration=acceleration;
        _radius=Radius;
        _position=position;
    }

Vector Particle::getPosition() {

    _position.x= mapToParent( 0 ,0 ).x();
    _position.y= mapToParent( 0 , 0).y();
    return _position; }

Vector Particle::getVelocity() { return _velocity;}

Vector Particle::getAcceleration(){ return _acceleration;}

void Particle::updateVelocity(Vector velocity){
        _velocity=velocity;
    }

void Particle::updateAcceleration(Vector acceleration) {
        _acceleration=acceleration;
    }

void Particle::updatePosition(){
        _position=_nextPosition;}



void Particle::set_pos(){
    setPos(_position.x,_position.y);
}


double Particle::getRadius(){ return _radius; }

double Particle::getMass(){ return _mass; }




void Particle::move(double t){    //t is going to be very small
        Vector p;

        _position.x= mapToParent( 0 ,0 ).x();
        _position.y= mapToParent( 0 , 0).y();

        if(((Xright - _position.x < 0) && (_velocity.x > 0))  || (((_position.x - Xleft) < 0) && (_velocity.x < 0)) )
            _velocity.x = - _velocity.x;

        if((((Ytop - _position.y) < 0) && (_velocity.y > 0))|| (((_position.y - Ybottom) < 0) && (_velocity.y < 0)))
            _velocity.y = - _velocity.y;


        p.x = _velocity.x*t + _acceleration.x*t*t/2;
        p.y = _velocity.y*t + _acceleration.y*t*t/2;
        //std::cout<<"::ye hai "<<p.x<<":"<<p.y<<":"<<t<<"   :   "<<_velocity.y<<std::endl;
        _nextPosition = (_position + p);
        //_nextPosition=_position+Vector(3,4);
        _velocity.x += _acceleration.x*t;
         _velocity.y += _acceleration.y*t;
    }






QRectF Particle::boundingRect() const
{
    qreal adjust = 0.5;
    return QRectF(-18 - adjust, -22 - adjust,
                  36 + adjust, 60 + adjust);
}

QPainterPath Particle::shape() const
{
    QPainterPath path;
    path.addRect(-radius, -radius, radius, radius);
    return path;
}


void Particle::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    // Body
    painter->setBrush(color);
    painter->drawEllipse(-radius, -radius, radius, radius);

}

void Particle::advance(int step)
{

    if (!step)
      return;

    //_position = _nextPosition;
    // setPos(_position.x,_position.y);

}
