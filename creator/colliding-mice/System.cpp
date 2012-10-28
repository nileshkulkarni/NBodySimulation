#include "System.h"

#include "System.h"
#include "AllClasses.h"
#include "mouse.h"
#include <iostream>
#include <cmath>


System::System(){
}

System::System(int k,  double probeInterval){
    _particles.resize(k);
    _NoOfParticles=k;
   _probeInterval=probeInterval;
}

void System::addItem(Particle* P , int index){
    _particles[index]=P;
}


void System :: detectCollision(){
    for(int i = 0;i<_NoOfParticles;i++){
        for(int j=i+1; j< _NoOfParticles;j++){
            if(i==j){
                continue;
            }
            else{
                //Particle p1 = (*it1);
                //Particle p2 = (*it2);
                float radius1 =_particles[i]->getRadius();
                float radius2 =_particles[j]->getRadius();
                Vector point1 =	_particles[i]->getPosition();
                Vector point2 =  _particles[j]->getPosition();
                Vector p      = point1 - point2;
                if(p.modulo() <= (radius1 +radius2)){
                    //Particle *pp1 = it1;
                //	Particle *pp2 = it2;
                    actOnCollision(i,j);
                }
            }
        }
    }

}

void System:: actOnCollision(int i , int j){
    Vector point1 = _particles[i]->getPosition();
    Vector point2 = _particles[j]->getPosition();
    Vector parallel = point1 - point2 ;
    std::cout<<"ye   "<<parallel.x<<"   ::   "<<parallel.y<<"  ::  "<<parallel.modulo()<<std::endl;
    //parallel = parallel /  parallel.modulo();
    parallel.normalize();
    std::cout<<"ye kya hai   "<<parallel.x << "  ::  "<<parallel.y<<std::endl;
    Vector p1Velocity = _particles[i]->getVelocity();

    Vector p2Velocity =_particles[j]->getVelocity();


    Vector perp  =  Vector(parallel.y , -parallel.x);




//   if((p1Velocity-p2Velocity)* parallel <= 0) return;


    double p1parallel = parallel * p1Velocity;
    double p2parallel = parallel * p2Velocity;
    double p1perp = perp * p1Velocity;
    double p2perp = perp* p2Velocity;

    if((parallel * (p1Velocity - p2Velocity)) >= 0) return;

    _particles[i]->updateVelocity( (parallel * p2parallel) + (perp * p1perp));
    _particles[j]->updateVelocity( (parallel * p1parallel) + (perp * p2perp));


    /*
    if((_particles[i]->getVelocity()
    {
        std::cout<<"***************************************"<<std::endl;
        std::cout<<"modulo is " <<parallel.modulo()<<std::endl;
        std::cout<<"position 1 "<< point1.x <<": " <<point1.y <<std::endl;
        std::cout<<"position 2 "<< point2.x <<": " <<point2.y <<std::endl;
        std::cout<<"parallel "<< parallel.x <<": " <<parallel.y <<std::endl;
        std::cout<<"perp "<< perp.x <<": " <<perp.y <<std::endl;
        //std::cout<<"parallep1  "<< p <<"    :    "<<p1parallel.y<<std::endl;

        std::cout<<p1Velocity.x<<","<<p1Velocity.y<<" ::  "<<p2Velocity.x<<","<<p2Velocity.y<<std::endl;
        std::cout<<(_particles[i]->getVelocity()).x<<","<<(_particles[i]->getVelocity()).y<<"   ::   ";
        std::cout<<(_particles[j]->getVelocity()).x<<","<<(_particles[j]->getVelocity()).y<<std::endl;
   }*/

}


/*
void System:: Pause(){
    //std::cout<<"chalta hai"<<std::endl;
timer1.
}
*/






 void System:: run(){
     //std::cout<<"chalta hai"<<std::endl;

       detectCollision();

     for(int i=0;i< _NoOfParticles;i++){
         _particles[i]->move(_probeInterval);

         _particles[i]->updatePosition();

         _particles[i]->set_pos();

         std::cout<<"x :: " << (_particles[i]->getPosition().x) << "y ::" <<(_particles[i]->getPosition().y) << std::endl;
     }


     resetAcceleration();


}





 void System::resetAcceleration(){
     for(int i = 0;i<_NoOfParticles;i++){
         Vector newAccel(0,0);
         Vector pos = _particles[i]->getPosition();
         for(int j=0; j< _NoOfParticles;j++){
             if(i==j) continue;
             Vector displacement=_particles[j]->getPosition()-pos;
             double modAccel =((Kg * _particles[j]->getMass())/ pow(displacement.modulo(),3));
             newAccel.x += displacement.x *  modAccel;
             newAccel.y += displacement.y *  modAccel;
         }

         _particles[i]->updateAcceleration(newAccel);

      }

 }


























