#include "../includes/monom.h"
#include "../includes/polinom.h"
#include "../includes/calc.h"
#include <string>

polinom calc::parser (string s) {
    int n = s.size();
    polinom res;
    double k = 0;
    int st = 1;
    int i = n - 1;

    link* t = new link();
    while (i >= 0) {
        while (i >= 0 && (s[i] < '0' || s[i] > '9')) i--;
        while (i >= 0 && s[i] >= '0' && s[i] <= '9') {
            k += st * (s[i] - '0');
            st *= 10;    
            i--;
            if (i >= 0 && ((s[i] == '.') || (s[i] == ','))) {
                k /= (double)st;
                st = 1;
                i--;
            }
        }
        st = 1;
        while (i >= 0 && s[i] != 'x' && s[i] != 'y' && s[i] != 'z' && s[i] != '+' && s[i] != '-') i--;
        if (i < 0) {
            t->a = k;
            res.add (*t);
            return res;
        }
        switch (s[i])
        {
            case 'x':
                t->deg_x = k;
                k = 0;    
                break;
            case 'y':
                t->deg_y = k;
                k = 0;
                break;
            case 'z':
                t->deg_z = k;
                k = 0;
                break;
            default:
                t->a = (s[i] == '+' ? k : -k);
                k = 0;
                res.add (*t);
                t = new link();
                break;
        }
    }
    return res;
}