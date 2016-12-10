//
// Created by Pol Valls Ortiz on 10/12/2016.
//

#include "Dades.hh"

Dades::Dades() {

}

void Dades::afegir_op(string ref, string exp, list<string> param) {
    Operacio op;
    op.afegir_op(exp,param);
    map_op[ref] = op;
}

void Dades::afegir_dada(string ref, Resultat dada) {
    map_data[ref] = dada;
}

bool Dades::existeix_op(string ref) {
    map<string,Operacio>::iterator it = map_op.find(ref);
    if(it == map_op.end()) return false;
    else return true;
}

bool Dades::existeix_dada(string ref) {
    map<string,Resultat>::iterator it = map_data.find(ref);
    if(it == map_data.end()) return false;
    else return true;
}

Operacio Dades::consultar_operacio(string ref) {
    return map_op[ref];
}

Resultat Dades::consultar_dada(string ref) {
    return map_data[ref];
}