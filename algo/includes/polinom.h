#pragma once

#include "monom.h"

class polinom {
public:
    link* head;
    polinom ();    
    void add (int deg_x, int deg_y, int deg_z, double a);
    void add (const link& x);
    friend ostream& operator<<(ostream& out, const polinom& t);
    friend polinom operator+(const polinom& x,const polinom& y);
    friend polinom operator*(const polinom& x, const    polinom& y);
};
