#ifndef ALLCLASSES_H

#define ALLCLASSES_H






    class Vector{
        public:
        double x;
        double y;

        Vector();
        Vector(double  a,double b);
        Vector operator -(Vector P);
        Vector operator -();
        Vector operator +(Vector P);
        double operator *(Vector P); //dot product
        double operator ^(Vector P);	//cross product
        Vector operator *(double k);
        Vector operator /(double k);
        void operator =(Vector P);
        double modulo();
        void normalize();


    };



#endif // ALLCLASSES_H
