#include "Expressio.hh"
#include "Dades.hh"
#include "Operacio.hh"
#include "Resultat.hh"
#ifndef NO_DIAGRAM
#include <iostream>
#include <sstream>
#include <string>
#include <map>
#endif
using namespace std;


/** @brief Programa principal per a la pràctica <em><b>Calculadora d'expressions aritmètiques</b></em>.
*/

string obtenir_expressio() {
    int counter = 0;
    bool first = true;
    string resultat,total;
    while(counter != 0 or first) {
        if(first) first = false;
        cin >> resultat;
        for(int i = 0; i < resultat.length(); ++i){
            if(resultat[i] == '(') ++counter;
            if(resultat[i] == ')') --counter;
        }
        if(total.length() != 0) {
            if (total[total.length() - 1] == ')' and resultat == ")") total += resultat;
            else total += " " + resultat;
        }
        else total = resultat;
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
    data.finalitzar();
}