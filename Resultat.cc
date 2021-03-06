/** @file Resultat.cc
    @brief Implementacó de la classe Resultat de <em>Calculadora d'expressions</em>.
*/

#include "Resultat.hh"

Resultat::Resultat() {
    descripcio = "indefinit";
}

void Resultat::afegir_enter_bool(int enter_bool) {
    enterbool = enter_bool;
}

void Resultat::afegir_llista(list<int> llista_ints) {
    llistaenters = llista_ints;
}

void Resultat::afegir_enter_llista(int enter_llista) {
    llistaenters.push_back(enter_llista);
}

void Resultat::afegir_enter_llista_davanter(int enter_llista) {
    llistaenters.push_front(enter_llista);
}

void Resultat::afegir_descripcio(string desc) {
    descripcio = desc;
}

void Resultat::esborrar_enter_llista() {
    llistaenters.pop_front();
}

int Resultat::consultar_top() {
    return llistaenters.front();
}

list<int> Resultat::consultar_llista() {
    return llistaenters;
}

int Resultat::consultar_enter() {
    return enterbool;
}

string Resultat::consultar_descripcio() {
    return descripcio;
}

bool Resultat::es_boolea() {
    if(descripcio == "enter" and (enterbool == 0 or enterbool == 1)) return true;
    else return false;
}

