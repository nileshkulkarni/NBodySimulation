#include "AllClasses.h"

namespace local            
{
	
	//Class Particle
	
	Particle::Particle()
	{
		_velocity = 0;
	}
	
	
	Particle::Particle(double mass = particleMass, double velocity =0 , double acceleration = 0, double radius=particleRadius , Point position)
	{
		_mass=particleMass;
		_velocity=velocity;
		_acceleration=acceleration;
		_radius=radius;
		_position=position;
	}
	Point Particle::getPosition() { return _position; }
	Vector Particle::getVelocity() { return _velocity;}
    Vector Particle::getAcceleration(){ return _acceleration;}
    Vector Particle::getRadius(){ return _radius; }
    
    void Particle::updateVelocity(Vector velocity){_velocity=velocity;}
	void Particle::updateAcceleration(Vector acceleration) { _acceleration=acceleration;}
	void Particle::updatePosition(Point point){ _position=point; }
	//void Particle::addCoordinates(Point point){ _position + point;  }
	
	
	//end of class Particle
	
	double Particle::getAcceleration(){ return _acceleration;}
   	double Particle::getRadius(){ return _radius; }
	double Particle::move(double t){
		Point p;
		p.x = _velocity.x*t + _acceleration.x*t*t/2;
		p.y = _velocity.y*t + _acceleration.y*t*t/2;
		_position = (_position + p);	
	}	
}	
