

namespace local {
	
	#define particleMass 1
	#define particleRadius 1
	
	
	class Point{
		public:
		float x;
		float y;
		
	};
	

	class Particle{
		private:
		float _mass;
		Point _position;
		double _velocity;
		double _acceleration;
		double _radius;

		public:
		
		Particle();
		Particle(float mass = particleMass, double velocity =0 , double acceleration = 0, double radius=particleRadius , double position); 
		Point getPosition();
		double getVelocity();
		
		double getAcceleration();
		double getRadius();

	};

