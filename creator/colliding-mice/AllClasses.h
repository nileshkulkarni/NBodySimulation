#ifndef ALLCLASSES_H
#define ALLCLASSES_H

#endif // ALLCLASSES_H



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
