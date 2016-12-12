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

string Dades::definir_operacio(string ref, list<int> param2) {
    string resultat;
    Operacio op = map_op[ref];
    list<string> parametres = op.consultar_parametres();
    //ITERADORS
    list<string>::iterator itp = parametres.begin();
    list<int>::iterator itpos = param2.begin();
    resultat = op.consultar_expressio();
    while(itp != parametres.end()) {
        string actual;
        istringstream iss(resultat);
        resultat = "";
        while(iss >> actual) {
            string parentesis = "";
            while(actual[(actual.length()-1)] == ')') {
                actual.erase(actual.length()-1);
                parentesis += ")";
            }
            if(actual == *itp) {
                int afegir = *itpos;
                string afegirstr = to_string(afegir);
                resultat += " " + afegirstr + parentesis;
            }
            else resultat += " " + actual + parentesis;
        }
        ++itp;
        ++itpos;
    }
    resultat.erase(0,1);
    return resultat;
}

Operacio Dades::consultar_operacio(string ref) {
    return map_op[ref];
}

Resultat Dades::consultar_dada(string ref) {
    return map_data[ref];
}