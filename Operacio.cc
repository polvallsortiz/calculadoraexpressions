/** @file Operacio.cc
    @brief Implementació de la classe Operació
*/
#include "Operacio.hh"

Operacio::Operacio() {

}

void Operacio::afegir_op(string exp, list<string> param) {
    parametres = param;
    expressio = exp;
}

int Operacio::consultar_numero_parametres() {
    return parametres.size();
}

string Operacio::consultar_expressio() {
    return expressio;
}