#include "System.h"
#include "AllClasses.h"

System::System(){
	int i =0;
}

void System :: detectCollision(){
	typename::std::vector<Particle>::iterator it1;
	typename::std::vector<Particle>::iterator it2;

	for(it1=_particles.begin();it1 != _particles.end();it1++){
		for(it2=_particles.begin();it2  != _particles.end();it2++){
			if(it1 == it2){
				continue;
			}
			else{
				Particle p1 = (*it1);
				Particle p2 = (*it2);
				float radius1 =p1.getRadius();	
				float radius2 =p2.getRadius();
				Vector point1 =	p1.getPosition();
				Vector point2 =  p2.getPosition();
				Vector p      = point1 -point2;
				if(p.modulo() <= (radius1 +radius2)){
					//Particle *pp1 = it1;
				//	Particle *pp2 = it2;
					actOnCollision(it1,it2);
				}
			}
		}
	}

}

void System:: actOnCollision(std::vector<Particle>::iterator p1 ,std::vector<Particle> :: iterator p2){
	Vector point1 = (*p1).getPosition();	
	Vector point2 = (*p2).getPosition();
	Vector parallel = point1 -point2 ;
	Vector p1Velocity = (*p1).getVelocity();
	Vector p2Velocity =(*p2).getVelocity();
	Vector perp  =  Vector(parallel.y , -parallel.x);
	Vector p1parallel = parallel* (p1Velocity*parallel/(parallel*parallel));
	Vector p2parallel = parallel* (p2Velocity*parallel/(parallel*parallel));
	Vector p1perp = perp * (p1Velocity*perp/(perp.modulo() * perp.modulo()));
	Vector p2perp = perp * (p2Velocity*perp/(perp.modulo() * perp.modulo()));
	float p1finalx= (p2parallel + p1perp) * Vector(1,0) ;
	float p1finaly=(p2parallel + p1perp) * Vector(0,1);
	float p2finalx= (p1parallel + p2perp) * Vector(1,0) ;
	float p2finaly=(p1parallel + p2perp) * Vector(0,1);
	
	(*p1).updateVelocity(Vector(p1finalx,p1finaly));	
	(*p2).updateVelocity(Vector(p2finalx,p2finaly));
}





	
	











