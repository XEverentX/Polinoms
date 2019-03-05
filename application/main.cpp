#include<iostream>
#include<string.h>
#include<stdio.h>
#include"../algo/includes/calc.h"

#define cls printf("\033" "c")

int main() {
    polinom res1, res2;
    calc calculator;
    //cls;
    while (true) {
        cls;
        cout << "Use the nuber of polinom to enter it. Use format:(12x^3y^2z^17+...)\n For add(+) or mul(*) polinoms, enter the appropriate sign\n";
        cout << "1) ";
        res1.head == NULL ? cout << "Empty" : cout << res1;
        cout << "\n2) ";
        res2.head == NULL ? cout << "Empty" : cout << res2;
        cout << "\n3) Exit\n\n";
        char x;
        cin >> x;
        cout << "\n";
            if (x == '1') {
                string s;
                cin >> s;
                res1 = calculator.parser (s);
            } else

            if (x == '2') {
                string s;
                cin >> s;
                res2 = calculator.parser (s);
            } else
                
            if (x == '+') {
                if (res1.head == NULL || res2.head == NULL) throw 1;
                res1 = res1 + res2;
                cout << res1;
                cout << "\n\n1) Back to menu(Result will be wroten in the first operand)\n";
                int g;
                cin >> g;
            } else
            
            if (x == '*') {
                if (res1.head == NULL || res2.head == NULL) throw 1;
                res1 = res1 * res2;
                cout << res1;
                cout << "\n\n1) Back to menu(Result will be wroten in the first operand)\n";
                int g;
                cin >> g;
            } else {
                return 0;
            }
    }
    return 0;    
}
