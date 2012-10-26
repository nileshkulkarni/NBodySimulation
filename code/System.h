#ifndef SYSTEM
#define SYSTEM
#include "AllClasses.h"
#include <vector>
class System{
	
	private:
	std::vector<Particle> _particles;
	double _simTime;
	double _probeInterval;
	int _NoOfParticles;
	double probeInterval;
	
	public:
	System();	
	void detectCollision();
	void actOnCollision(std::vector<Particle> :: iterator p1,std::vector<Particle>::iterator p2);
	


	};

#endif

