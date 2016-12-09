/** @file Expressio.cc
    @brief Implementació de la classe Expressio de <em>Calculadora d'expressions aritmètiques</em>.
*/

#include "Expressio.hh"

void Expressio::inicialitzar(string comanda) {
    list<string> llista;
    llegir_expressio(comanda,llista);
    Resultat res = evaluar(llista);
    if(res.consultar_descripcio() == "bool") {
        if(res.consultar_enter() == 1) {
            cout << res.consultar_enter() << " " << "TRUE" << endl;
        }
        else {
            cout << res.consultar_enter() << " " << "FALSE" << endl;
        }
    }
    if(res.consultar_descripcio() == "enter") cout << res.consultar_enter() << " " << "ENTER" << endl;
    if(res.consultar_descripcio() == "llista") {
        list<int> listtemp;
        listtemp = res.consultar_llista();
        list<int>::iterator it = listtemp.begin();
        cout << listtemp.size() << endl;
        while(it != listtemp.end()) {
            cout << *it << " ";
            ++it;
        }
        cout << endl << "LLISTA" << endl;
    }
    if(res.consultar_descripcio() == "indefinit") {
        cout << "******** INDEFINIT ********" << endl;
    }
}

void Expressio::llegir_expressio(string s, list<string>& llista_expressio){
    if(s[0] == '(') {
        s.erase(0, 1);
        s.erase(s.size()-1);
    }
    istringstream iss(s);
    string frag = "";
    string tmp = "";
    int c = 0;
    while (iss >> tmp){
        for(int i = 0; tmp[i] == '('; i++)c++;
        for(int i = tmp.size() - 1; tmp[i] == ')'; i--)c--;
        frag += (frag == "" ? "" : " ") + tmp;
        if(c == 0){
            llista_expressio.push_back(frag);
            frag = "";
        }
    }
}


Resultat Expressio::evaluar(list<string> llista_expressio) {
    list<string>::iterator it = llista_expressio.begin();
    string op = *it;
    Resultat tres;
    if(op == "+") {
        ++it;
        string l = *it;
        list<string> llistal;
        llegir_expressio(l,llistal);
        Resultat lres = evaluar(llistal);
        ++it;
        string r = *it;
        list<string> llistar;
        llegir_expressio(r,llistar);
        Resultat rres = evaluar(llistar);
        tres.afegir_enter_bool(lres.consultar_enter()+rres.consultar_enter());
        tres.afegir_descripcio("enter");
    }
    if(op == "-") {
        ++it;
        string l = *it;
        list <string> llistal;
        llegir_expressio(l,llistal);
        Resultat lres = evaluar(llistal);
        tres.afegir_enter_bool(-lres.consultar_enter());
        tres.afegir_descripcio("enter");
    }
    if(op == "cons") {
        ++it;
        string l = *it;
        list<string> llistal;
        llegir_expressio(l,llistal);
        Resultat lres = evaluar(llistal);
        ++it;
        string r = *it;
        list<string> llistar;
        llegir_expressio(r,llistar);
        Resultat rres = evaluar(llistar);
        tres.afegir_llista(rres.consultar_llista());
        tres.afegir_enter_llista_davanter(lres.consultar_enter());
        tres.afegir_descripcio("llista");
    }
    if(op == "head") {
        ++it;
        string l = *it;
        list<string> llistal;
        llegir_expressio(l,llistal);
        Resultat lres = evaluar(llistal);
        tres.afegir_enter_bool(lres.consultar_top());
        tres.afegir_descripcio("enter");
    }
    if(op == "tail") {
        ++it;
        string l = *it;
        list<string> llistal;
        llegir_expressio(l,llistal);
        Resultat lres = evaluar(llistal);
        tres.afegir_llista(lres.consultar_llista());
        tres.esborrar_enter_llista();
        tres.afegir_descripcio("llista");
    }
    if(op == "=") {
        ++it;
        string l = *it;
        list<string> llistal;
        llegir_expressio(l,llistal);
        Resultat lres = evaluar(llistal);
        ++it;
        string r = *it;
        list<string> llistar;
        llegir_expressio(r,llistar);
        Resultat rres = evaluar(llistar);
        if(lres.consultar_descripcio() == "enter" and rres.consultar_descripcio() == "enter") {
            if(lres.consultar_enter() == rres.consultar_enter()) {
                tres.afegir_enter_bool(1);
                tres.afegir_descripcio("bool");
            }
            else {
                tres.afegir_enter_bool(0);
                tres.afegir_descripcio("bool");
            }
        }
        else {
            if(lres.consultar_descripcio() == "llista" and rres.consultar_descripcio() == "llista") {
                if(lres.consultar_llista() == rres.consultar_llista()) {
                    tres.afegir_enter_bool(1);
                    tres.afegir_descripcio("bool");
                }
                else {
                    tres.afegir_enter_bool(0);
                    tres.afegir_descripcio("bool");
                }
            }
            else {
                if(lres.consultar_descripcio() == "bool" and rres.consultar_descripcio() == "bool") {
                    if(lres.consultar_enter() == rres.consultar_enter()) {
                        tres.afegir_enter_bool(1);
                        tres.afegir_descripcio("bool");
                    }
                    else {
                        tres.afegir_enter_bool(0);
                        tres.afegir_descripcio("bool");
                    }
                }
                else {
                    tres.afegir_descripcio("indefinit");
                }
            }
        }
    }
    if(op == "<") {
        ++it;
        string l = *it;
        list<string> llistal;
        llegir_expressio(l,llistal);
        Resultat lres = evaluar(llistal);
        ++it;
        string r = *it;
        list<string> llistar;
        llegir_expressio(r,llistar);
        Resultat rres = evaluar(llistar);
        if(lres.consultar_descripcio() == "enter" and rres.consultar_descripcio() == "enter") {
            if(lres.consultar_enter() < rres.consultar_enter()) {
                tres.afegir_enter_bool(1);
                tres.afegir_descripcio("bool");
            }
            else {
                tres.afegir_enter_bool(0);
                tres.afegir_descripcio("bool");
            }

        }
        else {
            tres.afegir_descripcio("indefinit");
        }
    }
    if(op == "not") {
        ++it;
        string l = *it;
        list<string> llistal;
        llegir_expressio(l,llistal);
        Resultat lres = evaluar(llistal);
        if(lres.consultar_descripcio() == "bool") {
            if(lres.consultar_enter() == 0) tres.afegir_enter_bool(1);
            else tres.afegir_enter_bool(0);
            tres.afegir_descripcio("bool");
        }
        else tres.afegir_descripcio("indefinit");
    }
    if(op == "and") {
        ++it;
        string l = *it;
        list<string> llistal;
        llegir_expressio(l,llistal);
        Resultat lres = evaluar(llistal);
        ++it;
        string r = *it;
        list<string> llistar;
        llegir_expressio(r,llistar);
        Resultat rres = evaluar(llistar);
        if(lres.consultar_descripcio() == "bool" and rres.consultar_descripcio() == "bool") {
            if(lres.consultar_enter() == 1 and rres.consultar_enter() == 1) tres.afegir_enter_bool(1);
            else tres.afegir_enter_bool(0);
            tres.afegir_descripcio("bool");
        }
        else tres.afegir_descripcio("indefinit");
    }
    if(op == "or") {
        ++it;
        string l = *it;
        list<string> llistal;
        llegir_expressio(l,llistal);
        Resultat lres = evaluar(llistal);
        ++it;
        string r = *it;
        list<string> llistar;
        llegir_expressio(r,llistar);
        Resultat rres = evaluar(llistar);
        if(lres.consultar_descripcio() == "bool" and rres.consultar_descripcio() == "bool") {
            if(lres.consultar_enter() == 1 or rres.consultar_enter() == 1) tres.afegir_enter_bool(1);
            else tres.afegir_enter_bool(0);
            tres.afegir_descripcio("bool");
        }
        else tres.afegir_descripcio("indefinit");
    }
    if(op == "if") {
        ++it;
        string x = *it;
        list<string> llistax;
        llegir_expressio(x,llistax);
        Resultat xres = evaluar(llistax);
        ++it;
        string y = *it;
        list<string> llistay;
        llegir_expressio(y,llistay);
        Resultat yres = evaluar(llistay);
        ++it;
        string z = *it;
        list<string> llistaz;
        llegir_expressio(z,llistaz);
        Resultat zres = evaluar(llistaz);
        if(xres.consultar_descripcio() == "bool") {
            if(xres.consultar_enter() == 0) {
                if(yres.consultar_descripcio() == "llista") {
                    tres.afegir_descripcio("llista");
                    tres.afegir_llista(yres.consultar_llista());
                }
                if(yres.consultar_descripcio() == "enter") {
                    tres.afegir_descripcio("enter");
                    tres.afegir_enter_bool(yres.consultar_enter());
                }
                if(yres.consultar_descripcio() == "bool") {
                    tres.afegir_descripcio("bool");
                    tres.afegir_enter_bool(yres.consultar_enter());
                }
            }
            else {
                if(zres.consultar_descripcio() == "llista") {
                    tres.afegir_descripcio("llista");
                    tres.afegir_llista(zres.consultar_llista());
                }
                if(zres.consultar_descripcio() == "enter") {
                    tres.afegir_descripcio("enter");
                    tres.afegir_enter_bool(zres.consultar_enter());
                }
                if(zres.consultar_descripcio() == "bool") {
                    tres.afegir_descripcio("bool");
                    tres.afegir_enter_bool(zres.consultar_enter());
                }
            }
        }
        else tres.afegir_descripcio("indefinit");
    }
    else {
        if(llista_expressio.size() == 1) { //ENTER SOL
            istringstream enter(*it);
            int entertemp;
            enter >> entertemp;
            tres.afegir_enter_bool(entertemp);
            //BOOL OR ENTER HOW WE KNOW IT ISSUE#5 GitHub
            tres.afegir_descripcio("enter");
        }
        else { //LLISTA
            while(it != llista_expressio.end()) {
                istringstream enter(*it);
                int temp;
                enter >> temp;
                tres.afegir_enter_llista(temp);
                ++it;
            }
        }
    }
    return tres;
}


