#include "Expressio.hh"
#include "Dades.hh"
#ifndef NO_DIAGRAM
#include <iostream>
#include <sstream>
#include <string>
#endif
using namespace std;


/** @brief Programa principal per a la pràctica <em><b>Calculadora d'expressions aritmètiques</b></em>.
*/

string obtenir_expressio() {
    int counter = 0;
    string resultat,total;
    getline(cin,resultat);
    for(int i = 0; i < resultat.length(); ++i) {
        if(resultat[i] == '(') ++counter;
        if(resultat[i] == ')') --counter;
    }
    total = resultat;
    while(counter != 0) {
        getline(cin,resultat);
        for(int j = 0; j < resultat.length(); ++j) {
            if(resultat[j] == '(') ++counter;
            if(resultat[j] == ')') --counter;
        }
        total += resultat;
    }
    return total;
}

int main ()
{
    string comanda;
    Dades data;
    comanda = obtenir_expressio();
    while(comanda != "****" ) {
        if(comanda != "") {
            Expressio expr;
            expr.inicialitzar(comanda, data);
        }
        comanda = obtenir_expressio();
    }
}