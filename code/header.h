

namespace local {
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
		Point getPosition();
		double getVelocity();
		double getAcceleration();
		double getRadius();

	};

