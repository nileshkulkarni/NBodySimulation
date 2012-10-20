

namespace local {
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
		Point getPosition();
		double getVelocity();
		double getAcceleration();
		double getRadius();

	};

