#include "AllClasses.h"
#include <cmath>

	Vector::Vector(){
		x =0.0;
		y =0.0;
	}
	Vector::Vector(int a,int b){
		x=a;
		y=b;
	}
	Vector Vector :: operator -(){
		return Vector(-x ,-y);
	}

	void Vector :: operator =(Vector P){
		x=P.x;
		y=P.y;
	}


	Vector Vector :: operator -(Vector P){
		return Vector(x - P.x,y- P.y);
	}
	Vector Vector :: operator +(Vector P){
		return Vector(x +P.x,y+ P.y);
	}

	Vector Vector :: operator *(double k){
		Vector(x * k,+y* k);
	}
	double Vector :: operator *(Vector P){
		(x * P.x+y* P.y);
	}


	double Vector :: operator ^(Vector P){
		return (x * P.y - y* P.x);
	}

	double Vector :: modulo(){
		return sqrt(x*x +y*y);
	}

