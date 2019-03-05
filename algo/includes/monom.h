#pragma once

#include <iostream>

using namespace std;

struct link {
    int deg_x;
    int deg_y;
    int deg_z;
    double a;
    link* next;
    link (int deg_x = 0, int deg_y = 0, int deg_z = 0, int a = 0) {
        this->deg_x = deg_x;
        this->deg_y = deg_y;
        this->deg_z = deg_z;
        this->a = a;
        this->next = NULL;
    }
    link (const link& t) {
        this->deg_x = t.deg_x;
        this->deg_y = t.deg_y;
        this->deg_z = t.deg_z;
        this->a = t.a;
        this->next = NULL;
    }

    friend bool operator<(const link& x, const link& y);
    friend bool operator>=(const link& x, const link& y);
    friend bool operator==(const link& x, const link& y);
    friend link operator*(const link& x, const link& y);
    friend ostream& operator<<(ostream& out, const link& t);
    friend istream& operator>>(istream& in, link& t);
};