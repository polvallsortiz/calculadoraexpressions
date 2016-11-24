/** @file pro2_s8.cc
    @brief Implementacó de les operacions definides de <em>Calculadora d'expressions</em>.
*/

#include "Operacions.hh"

void Operacions::Operacions(
    operacions_predefinides.push_back("+");
    operacions_predefinides.push_back("-");
    operacions_predefinides.push_back("cons");
    operacions_predefinides.push_back("head");
    operacions_predefinides.push_back("tail");
    operacions_predefinides.push_back("=");
    operacions_predefinides.push_back("<");
    operacions_predefinides.push_back("not");
    operacions_predefinides.push_back("and");
    operacions_predefinides.push_back("or");
    operacions_predefinides.push_back("if");
}

void Operacions::afegir_operacio(string index, string s) {
    operacions_definides.emplace(index,s);
}

int Operacions::suma(int &x, int &y) {
    return x + y;
}

int Operacions::intercanviador(int &x) {
    return (x-(2*x));
}

void Operacions::afegidor(int x, list<int> &y) {
    return y.push_front (x);
}

int Operacions::top_llista(list<int> x) {
    return x.front();
}

list<int> Operacions::pop_llista(list<int> x) {
    return x.pop_front();
}

int Operacions::igualtat (int x, int y) {
    if (x == y) return 1;
    else return 0;
}

int Operacions::petit (int x, int y) {
    if (x < y) return 1;
    else return 0;
}

int Operacions::negacio (int x) {
    if (x == 1) return 0;
    if (x == 0) return 1;
}

int Operacions::comparacio_OR(int x, int y) {
    if (x == 1 or y == 1) return 1;
    else return 0;
}

int Operacions::comparacio_AND(int x, int y) {
    if (x == 1 && x == 1) return 1;
    else return 0;
}

int Operacions::if_y_z_bool_enter(int x, int y, int z) {
    if ()
}

 int Operacions::if_y_z_bool(int x) {
     // if (x == 1) return aval(y);
       //  else if (x == 0) return aval(z);
       }