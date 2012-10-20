
#include "AllClasses.h"




namespace local           //nilu ka robosub ka dimag XD 
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
	double Particle::getVelocity() { return _velocity;}
    double Particle::getAcceleration(){ return _acceleration;}
    double Particle::getRadius(){ return _radius; }
    
    void Particle::updateVelocity(double velocity){_velocity=velocity;}
	void Particle::updateAcceleration(double acceleration) { _acceleration=acceleration;}
	void Particle::updatePosition(Point point){ _position=point; }
	void Particle::addCoordinates(Point point){ _position=_position + point;  }
	
	
	//end of class Particle
	
	 

}
