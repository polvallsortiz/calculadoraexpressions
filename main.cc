#include "Expressio.hh"
#ifndef NO_DIAGRAM 
#include <iostream>
#include <sstream>
#include <string>
#endif
using namespace std;


/** @brief Programa principal per a la pràctica <em><b>Calculadora d'expressions aritmètiques</b></em>.
*/

int main ()
{
    string comanda;
    getline(cin,comanda);
    while(comanda != "****" ) {
        Expressio expr;
        expr.inicialitzar(comanda);
        getline(cin,comanda);
    }
}