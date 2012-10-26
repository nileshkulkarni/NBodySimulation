#include "AllClasses.h"
#include <cmath>
namespace local{      
      
      
      Vector::Vector (double a, double b){ x=a; y=b; }
	  void  Vector::operator =(Vector P){ x=P.x; y=P.y; }
	  double Vector::length() { return sqrt(x*x + y*y); }	
	  
	  
	  
	  
	  
}	  
