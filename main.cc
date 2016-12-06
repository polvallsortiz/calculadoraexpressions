#include "Dades.hh"
#include "Operacions.hh"
#include "Expressio.hh"
#ifndef NO_DIAGRAM 
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
#endif

/** @brief Programa principal per a la pràctica <em><b>Calculadora d'expressions aritmètiques</b></em>.
*/

int main ()
{
    Dades data;
    Operacions op;
    string comanda;
    getline(cin,comanda);
    while(comanda != "****" ) {
        Expressio actual;
        actual.llegir_expressio(comanda);
        if(actual.first_expressio() == "+") {
            if(actual.length_expressio() == 3) {

            }
            else cout << "indefinit" << endl;
        }
        getline(cin,comanda);
    }
}