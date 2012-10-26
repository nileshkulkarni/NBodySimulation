#include "AllClasses.h"

	
	//Class Particle
	
	Particle::Particle()
	{
		_velocity = Vector(0,0);
	}
	
	
	Particle::Particle(double mass, Vector velocity , Vector acceleration  , double radius, Vector position)
	{
		_mass=mass;
		_velocity=velocity;
		_acceleration=acceleration;
		_radius=radius;
		_position=position;
	}
	Vector Particle::getPosition() { return _position; }
	Vector Particle::getVelocity() { return _velocity;}
        Vector Particle::getAcceleration(){ return _acceleration;}
        void Particle::updateVelocity(Vector velocity){
	    _velocity=velocity;
	}
	void Particle::updateAcceleration(Vector acceleration) { 
		_acceleration=acceleration;
	}
	void Particle::updatePosition(Vector point){ 
		_position=point;}
	//void Particle::addCoordinates(Vector point){ _position + point;  }
	
	
	//end of class Particle
	
   	double Particle::getRadius(){ return _radius; }
	void Particle::move(double t){
		Vector p;
		p.x = _velocity.x*t + _acceleration.x*t*t/2;
		p.y = _velocity.y*t + _acceleration.y*t*t/2;
		_position = (_position + p);	
	}		
