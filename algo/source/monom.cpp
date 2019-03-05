#include "../includes/monom.h"

using namespace std;

bool operator < (const link& x, const link& y) {
   if (x.deg_x < y.deg_x) return true;
   if (x.deg_x == y.deg_x) {
       if (x.deg_y < y.deg_y) return true;
       if (x.deg_y == y.deg_y) {
           if (x.deg_z < y.deg_z) return true;
       }
   }
   return false;
}

bool operator >= (const link& x, const link& y) {
   if (x.deg_x < y.deg_x) return false;
   if (x.deg_x == y.deg_x) {
       if (x.deg_y < y.deg_y) return false;
       if (x.deg_y == y.deg_y) {
           if (x.deg_z < y.deg_z) return false;
       }
   }
   return true; 
}

bool operator == (const link& x, const link& y) {
    if (x.deg_x == y.deg_x && x.deg_y == y.deg_y && x.deg_z == y.deg_z) return true;
    return false;
}

link operator*(const link& x, const link& y) {
    link res;
    res.deg_x = x.deg_x + y.deg_x;
    res.deg_y = x.deg_y + y.deg_y;
    res.deg_z = x.deg_z + y.deg_z;
    res.a = x.a * y.a;
    return res;
}

ostream& operator<<(ostream& out, const link& t) {
    out << "(" << t.a << " * ";
    out << "x^" << t.deg_x << " * y^" << t.deg_y << " * z^" << t.deg_z << ")";
}
istream& operator>>(istream& in, link& t) {
    in >> t.a >> t.deg_x >> t.deg_y >> t.deg_z;
}
