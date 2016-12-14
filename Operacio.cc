/** @file Operacio.cc
    @brief Implementació de la classe Operació
*/
#include "Operacio.hh"

Operacio::Operacio() {

}

void Operacio::afegir_op(string exp, list<string> param, bool correctesa) {
    if(param.size() == 1) {
        string parame = *param.begin();
        parame.erase(0,1);
        parame.erase(parame.length()-1);
        list<string> temp;
        temp.push_back(parame);
        parametres = temp;
    }
    else parametres = param;
    evaluable = correctesa;
    expressio = exp;
}

bool Operacio::consultar_validesa() {
    return evaluable;
}

int Operacio::consultar_numero_parametres() {
    return parametres.size();
}

string Operacio::consultar_expressio() {
    return expressio;
}

list<string> Operacio::consultar_parametres() {
    return parametres;
}