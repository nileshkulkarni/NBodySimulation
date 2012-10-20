

namespace local {
	
	#define particleMass 1
	#define particleRadius 1
	
	
	class Point{
		public:
		double x;
		double y;

		Point();
		Point operator -(Point P);
		Point operator -();
		Point operator +(Point P);
		double operator *(Point P); //dot product
		double operator ^(Point P);					//cross product
		double operator *(double k);
		double modulo();

		
	};
	

	class Particle{
		private:
		double _mass;
		Point _position;
		double _velocity;
		double _acceleration;
		double _radius;

		public:
		
		Particle();
		Particle(double mass = particleMass, double velocity =0 , double acceleration = 0, double radius=particleRadius , double position); 
		Point getPosition();
		double getVelocity();
		void updateVelocity(double velocity);
		void updateAcceleration(double acceleration);
		void updatePosition(Point point);
		double getAcceleration();
		double getRadius();

	};

	class System{
		private:
		vector<Particle> _particles;
		double simTime;








}
