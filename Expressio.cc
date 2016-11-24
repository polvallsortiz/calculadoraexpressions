/** @file Expressio.cc
    @brief Implementació de la classe Expressio de <em>Calculadora d'expressions aritmètiques</em>.
*/

#include "Operacions.hh"

void Expressio::llegir_expressio(string s) {
    istringstream iss(s);
    string act;
    iss >> act;
    act.erase(0, 1);
    int parcount = 0;
    llista_expressio.push_back(act);
    string resultat;
    while (iss >> act) {
        resultat = act;
        if (act[0] == '(') {
            ++parcount;
            resultat = act;
        }
        while (parcount != 0) {
            iss >> act;
            if (act[0] == '(') ++parcount;
            resultat += " " + act;
            while (act[act.size() - 1] == ')') {
                --parcount;
                act.erase(act.size() - 1);
            }
        }
        llista_expressio.push_back(resultat);
    }
    list<string>::iterator it = llista_expressio.end();
    --it;
    string ambpar = *it;
    ambpar.erase(ambpar.size() - 1);
    *it = ambpar;
}