namespace local           //nilu ka robosub ka dimag XD 
{
	Particle::Particle()
	{
		_velocity = 0;
	}
	
	
	Particle::Particle(float mass = particleMass, double velocity =0 , double acceleration = 0, double radius=particleRadius , Point position)
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


}
