#include "../includes/polinom.h"
#include "../includes/monom.h"
#include <iostream>

using namespace std;

polinom::polinom () {
    head = NULL;
}

void polinom::add (int deg_x, int deg_y, int deg_z, double a) {
    link* t = new link (deg_x, deg_y, deg_z, a);
    if (head == NULL) {
        head = new link (*t);
        delete t;
        return;
    }
    link *p = head;
    if (*p < *t) {
        t->next = p;
        head = t;
        return;
    }
    while (p->next != NULL && *p->next >= *t) p = p->next;
    if (*p == *t) {
        p->a += t->a;
        delete t;
        return;
    }
    if (p->next == NULL) {
        p->next = t;
        return;
    }
    if (p->next < t) {
        t->next = p->next;
        p->next = t;
        return;
    }
}

void polinom::add (const link& x) {
    link* t = new link (x);
    if (head == NULL) {
        head = new link (x);
        delete t;
        return;
    }
    link *p = head;
    if (*p < *t) {
        t->next = p;
        head = t;
        return;
    }
    while (p->next != NULL && *p->next >= *t) p = p->next;
    if (*p == *t) {
        p->a += t->a;
        delete t;
        return;
    }
    if (p->next == NULL) {
        p->next = t;
        return;
    }
    if (p->next < t) {
        t->next = p->next;
        p->next = t;
        return;
    }
}

ostream& operator<<(ostream& out, const polinom& t) {
    if (t.head != NULL) {
        link* p = t.head;
        while (p != NULL) {
            out << *p;
            if (p->next != NULL) out << " + ";
            p = p->next;
        }
    }
}

polinom operator+(const polinom& x, const polinom& y) {
    link* i = x.head;
    link* j = y.head;
    polinom res;
    while (i != NULL) {
        while (j != NULL && *j >= *i) res.add (*j), j = j->next;
        res.add (*i);
        i = i->next;
    }
    while (i != NULL) res.add (*i), i = i->next;
    while (j != NULL) res.add (*j), j = j->next;
    return res;
}

polinom operator*(const polinom& x, const polinom& y) {
    polinom res;
    for (link* i = x.head; i != NULL; i = i->next) {
        for (link* j = y.head; j != NULL; j = j->next) {
            res.add ((*i) * (*j));
        }
    }
    return res;
}