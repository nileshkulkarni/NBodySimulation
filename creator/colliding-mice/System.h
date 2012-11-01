#ifndef SYSTEM_H
#define SYSTEM_H

#include "AllClasses.h"
#include "mouse.h"
#include <vector>
#include <QObject>


#define Kg 0.01 //gravitational constant


class System : public QObject{
Q_OBJECT
private:
    std::vector<Particle*> _particles;
    double _simTime;
    double _probeInterval;
    int _NoOfParticles;
    //double probeInterval;

public:
    System();
    System(int k , double probeInterval);

    void addItem(Particle* P , int index);

    void detectCollision();
    void actOnCollision(int i,int j);
    void resetAcceleration();

public slots:
    void run();
    //void Pause();
    };



#endif // SYSTEM_H
