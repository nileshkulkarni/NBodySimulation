#ifndef ALL_CLASSES
#define ALL_CLASSES
	#define particleMass 1
	#define particleRadius 1
	
	
	class Vector{
		public:
		double x;
		double y;

		Vector();
		Vector(int a,int b);
		Vector operator -(Vector P);
		Vector operator -();
		Vector operator +(Vector P);
		double operator *(Vector P); //dot product
		double operator ^(Vector P);	//cross product
		Vector operator *(double k);
		void operator =(Vector P);
		
		
		double modulo();

		
	};
		
	
	
	

	class Particle{
		private:
		double _mass;
		Vector _position;
		Vector _velocity;
		Vector _acceleration;
		double _radius;

		public:
		
		Particle();
		Particle(double mass , Vector velocity  , Vector acceleration , double radius , Vector position); 
		Vector getPosition();
		void move(double t);
		Vector getVelocity();
		void updateVelocity(Vector velocity);
		void updateAcceleration(Vector acceleration);
		void updatePosition(Vector point);
	//	void addCoordinates(Vector point);
		
		Vector getAcceleration();
		double getRadius();

	};





//end of namespace local


#endif


