#include "Dades.hh"
#include "Operacions.hh"
#ifndef NO_DIAGRAM 
#include <iostream>
#include <sstream>
#include <string>
#endif

/** @brief Programa principal per a la pràctica <em><b>Calculadora d'expressions aritmètiques</b></em>.
*/

int main ()
{
    Dades data;
    Operacions op;
    string expressio,definitiva;
    getline(cin,expressio);
    while(expressio != "****" ) {
        definitiva = exp_completa(expressio);
        
        getline(cin,expressio);
    }
}  



/*
int main() {
    while(1) {
        expressio.afegir_expressio_llista();
        expressio.avaluar_subllistes();
        expressio.avaluar_totes_llistes()
    }
}










//Això seria una idea del que aniria a expressio.hh, en alguna funcio que fos de crear la llista amb els strings separats

/*#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
    string s;
    list<string> llegir;
    while (cin >> s and s != "****") {
        llegir.push_back(s);
    }
    for (list<string>::iterator it = llegir.begin(); it!=llegir.end(); ++it) {
        cout << *it << endl;
    }
}
    
*/