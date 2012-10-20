

namespace local {
	
	#define particleMass 1
	#define particleRadius 1
	
	
	class Point{
		public:
		float x;
		float y;

		Point();
		Point operator -(Point P);
		Point operator -();
		Point operator +(Point P);
		float operator *(Point P); //dot product
		float operator ^(Point P);//cross product
		float modulo();

		
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

