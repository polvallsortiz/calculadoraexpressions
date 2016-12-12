/** @file Expressio.cc
    @brief Implementació de la classe Expressio de <em>Calculadora d'expressions aritmètiques</em>.
*/

#include "Expressio.hh"

void Expressio::inicialitzar(string comanda,Dades& dat) {
    list<string> llista;
    llegir_expressio(comanda,llista);
    Resultat res = evaluar(llista,dat);
    if(res.consultar_descripcio() == "enter" or res.consultar_descripcio() == "llista" or res.consultar_descripcio() == "indefinit") {
        if (res.consultar_descripcio() == "enter") cout << res.consultar_enter() << endl;
        if (res.consultar_descripcio() == "llista") {
            list<int> listtemp;
            listtemp = res.consultar_llista();
            list<int>::iterator it = listtemp.begin();
            cout << "(" << *it;
            if(listtemp.size() != 0) {
                ++it;
                while (it != listtemp.end()) {
                    cout << " " << *it;
                    ++it;
                }
            }
            cout << ")" << endl;
        }
        if (res.consultar_descripcio() == "indefinit") {
            cout << "indefinit" << endl;
        }
    }
    else { //DEFINE DE OP
        if(res.consultar_descripcio() != "no") cout << res.consultar_descripcio() << " #" << res.consultar_enter() << endl;
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


Resultat Expressio::evaluar(list<string> llista_expressio, Dades& dat) {
    list<string>::iterator it = llista_expressio.begin();
    string op = *it;
    Resultat tres;
    if(op == "+" or op == "-" or op == "cons" or op == "head" or op == "tail" or op == "=" or op == "<" or op == "not" or op == "and" or op == "or" or op == "if" or op == "define") {
        if (op == "+") {
            ++it;
            string l = *it;
            list <string> llistal;
            llegir_expressio(l, llistal);
            Resultat lres = evaluar(llistal, dat);
            ++it;
            string r = *it;
            list <string> llistar;
            llegir_expressio(r, llistar);
            Resultat rres = evaluar(llistar, dat);
            tres.afegir_enter_bool(lres.consultar_enter() + rres.consultar_enter());
            tres.afegir_descripcio("enter");
        }
        if (op == "-") {
            ++it;
            string l = *it;
            list <string> llistal;
            llegir_expressio(l, llistal);
            Resultat lres = evaluar(llistal, dat);
            tres.afegir_enter_bool(-lres.consultar_enter());
            tres.afegir_descripcio("enter");
        }
        if (op == "cons") {
            ++it;
            string l = *it;
            list <string> llistal;
            llegir_expressio(l, llistal);
            Resultat lres = evaluar(llistal, dat);
            ++it;
            string r = *it;
            list <string> llistar;
            llegir_expressio(r, llistar);
            Resultat rres = evaluar(llistar, dat);
            tres.afegir_llista(rres.consultar_llista());
            tres.afegir_enter_llista_davanter(lres.consultar_enter());
            tres.afegir_descripcio("llista");
        }
        if (op == "head") {
            ++it;
            string l = *it;
            list <string> llistal;
            llegir_expressio(l, llistal);
            Resultat lres = evaluar(llistal, dat);
            tres.afegir_enter_bool(lres.consultar_top());
            tres.afegir_descripcio("enter");
        }
        if (op == "tail") {
            ++it;
            string l = *it;
            list <string> llistal;
            llegir_expressio(l, llistal);
            Resultat lres = evaluar(llistal, dat);
            tres.afegir_llista(lres.consultar_llista());
            tres.esborrar_enter_llista();
            tres.afegir_descripcio("llista");
        }
        if (op == "=") {
            ++it;
            string l = *it;
            list <string> llistal;
            llegir_expressio(l, llistal);
            Resultat lres = evaluar(llistal, dat);
            ++it;
            string r = *it;
            list <string> llistar;
            llegir_expressio(r, llistar);
            Resultat rres = evaluar(llistar, dat);
            if (lres.consultar_descripcio() == "enter" and rres.consultar_descripcio() == "enter") {
                if (lres.consultar_enter() == rres.consultar_enter()) {
                    tres.afegir_enter_bool(1);
                    tres.afegir_descripcio("enter");
                } else {
                    tres.afegir_enter_bool(0);
                    tres.afegir_descripcio("enter");
                }
            } else {
                if (lres.consultar_descripcio() == "llista" and rres.consultar_descripcio() == "llista") {
                    if (lres.consultar_llista() == rres.consultar_llista()) {
                        tres.afegir_enter_bool(1);
                        tres.afegir_descripcio("enter");
                    } else {
                        tres.afegir_enter_bool(0);
                        tres.afegir_descripcio("enter");
                    }
                } else {
                    if (lres.es_boolea() and rres.es_boolea()) {
                        if (lres.consultar_enter() == rres.consultar_enter()) {
                            tres.afegir_enter_bool(1);
                            tres.afegir_descripcio("enter");
                        }
                        else {
                            tres.afegir_enter_bool(0);
                            tres.afegir_descripcio("enter");
                        }
                    }
                    else {
                        tres.afegir_descripcio("indefinit");
                    }
                }
            }
        }
        if (op == "<") {
            ++it;
            string l = *it;
            list <string> llistal;
            llegir_expressio(l, llistal);
            Resultat lres = evaluar(llistal, dat);
            ++it;
            string r = *it;
            list <string> llistar;
            llegir_expressio(r, llistar);
            Resultat rres = evaluar(llistar, dat);
            if (lres.consultar_descripcio() == "enter" and rres.consultar_descripcio() == "enter") {
                if (lres.consultar_enter() < rres.consultar_enter()) {
                    tres.afegir_enter_bool(1);
                    tres.afegir_descripcio("enter");
                } else {
                    tres.afegir_enter_bool(0);
                    tres.afegir_descripcio("enter");
                }

            } else {
                tres.afegir_descripcio("indefinit");
            }
        }
        if (op == "not") {
            ++it;
            string l = *it;
            list <string> llistal;
            llegir_expressio(l, llistal);
            Resultat lres = evaluar(llistal, dat);
            if (lres.es_boolea()) {
                if (lres.consultar_enter() == 0) tres.afegir_enter_bool(1);
                else tres.afegir_enter_bool(0);
                tres.afegir_descripcio("enter");
            }
            else tres.afegir_descripcio("indefinit");
        }
        if (op == "and") {
            ++it;
            string l = *it;
            list <string> llistal;
            llegir_expressio(l, llistal);
            Resultat lres = evaluar(llistal, dat);
            ++it;
            string r = *it;
            list <string> llistar;
            llegir_expressio(r, llistar);
            Resultat rres = evaluar(llistar, dat);
            if (lres.es_boolea() and rres.es_boolea()) {
                if (lres.consultar_enter() == 1 and rres.consultar_enter() == 1) tres.afegir_enter_bool(1);
                else tres.afegir_enter_bool(0);
                tres.afegir_descripcio("enter");
            } else tres.afegir_descripcio("indefinit");
        }
        if (op == "or") {
            ++it;
            string l = *it;
            list <string> llistal;
            llegir_expressio(l, llistal);
            Resultat lres = evaluar(llistal, dat);
            ++it;
            string r = *it;
            list <string> llistar;
            llegir_expressio(r, llistar);
            Resultat rres = evaluar(llistar, dat);
            if (lres.es_boolea() and rres.es_boolea()) {
                if (lres.consultar_enter() == 1 or rres.consultar_enter() == 1) tres.afegir_enter_bool(1);
                else tres.afegir_enter_bool(0);
                tres.afegir_descripcio("enter");
            }
            else tres.afegir_descripcio("indefinit");
        }
        if (op == "if") {
            ++it;
            string x = *it;
            list <string> llistax;
            llegir_expressio(x, llistax);
            Resultat xres = evaluar(llistax, dat);
            ++it;
            if(xres.es_boolea()) {
                if (xres.consultar_enter() == 1) {
                    string y = *it;
                    list<string> llistay;
                    llegir_expressio(y, llistay);
                    Resultat yres = evaluar(llistay, dat);
                    if (yres.consultar_descripcio() == "llista") {
                        tres.afegir_descripcio("llista");
                        tres.afegir_llista(yres.consultar_llista());
                    }
                    if (yres.consultar_descripcio() == "enter") {
                        tres.afegir_descripcio("enter");
                        tres.afegir_enter_bool(yres.consultar_enter());
                    }
                } else {
                    ++it;
                    string z = *it;
                    list<string> llistaz;
                    llegir_expressio(z, llistaz);
                    Resultat zres = evaluar(llistaz, dat);
                    if (zres.consultar_descripcio() == "llista") {
                        tres.afegir_descripcio("llista");
                        tres.afegir_llista(zres.consultar_llista());
                    }
                    if (zres.consultar_descripcio() == "enter") {
                        tres.afegir_descripcio("enter");
                        tres.afegir_enter_bool(zres.consultar_enter());
                    }
                }
            }
            else tres.afegir_descripcio("indefinit");
        }
        if (op == "define") {
            ++it;
            string ref = *it;
            ++it;
            if (it == (--llista_expressio.end())) { //DEFINE DE ENTER/LLISTA ENTERS
                string ent = *it;
                list <string> llistaent;
                llegir_expressio(ent, llistaent);
                tres = evaluar(llistaent, dat);
                dat.afegir_dada(ref, tres);
                cout << ref << " ";
                if (tres.consultar_descripcio() == "enter") cout << tres.consultar_enter() << endl;
                if (tres.consultar_descripcio() == "llista") {
                    cout << "(";
                    list<int> templist = tres.consultar_llista();
                    list<int>::iterator itlist = templist.begin();
                    cout << *itlist;
                    ++itlist;
                    while (itlist != templist.end()) {
                        cout << " " << *itlist;
                        ++itlist;
                    }
                    cout << ")" << endl;
                }
                tres.afegir_descripcio("no");
            } else { //DEFINE DE OPERACIÓ
                string param = *it;
                list <string> llistaparam;
                llegir_expressio(param, llistaparam);
                int numparam = llistaparam.size();
                ++it;
                string exp = *it;
                dat.afegir_op(ref, exp, llistaparam);
                tres.afegir_descripcio(ref);
                tres.afegir_enter_bool(numparam);
            }
        }
    }
    else { //O OP DEFINIDA, DADA DEFINIDA, ENTER SOL, LLISTA D'ENTERS
        if(op < "0" or op > "9") { //DADA DEFINIDA OP
            if (dat.existeix_op(op)) { //EXISTEIX OP A DADES
                Operacio operacio = dat.consultar_operacio(op);
                list<int> parametres;
                int numparametres = operacio.consultar_numero_parametres();
                while (numparametres != 0) {
                    ++it;
                    list <string> llistal;
                    llegir_expressio(*it, llistal);
                    Resultat lres = evaluar(llistal, dat);
                    if (lres.consultar_descripcio() == "enter") parametres.push_back(lres.consultar_enter());
                    --numparametres;
                }
                string post = dat.definir_operacio(op, parametres);
                list <string> llistapost;
                llegir_expressio(post, llistapost);
                tres = evaluar(llistapost, dat);
                tres.afegir_descripcio("enter");
            }
            else {
                if (dat.existeix_dada(op)) tres = dat.consultar_dada(op);
            }
        }
        else {
            if (llista_expressio.size() == 1) { //ENTER/LLETRA SOLA
                istringstream enter(*it);
                int entertemp;
                enter >> entertemp;
                tres.afegir_enter_bool(entertemp);
                //BOOL OR ENTER HOW WE KNOW IT ISSUE#5 GitHub
                tres.afegir_descripcio("enter");
            }
            else { //LLISTA D'ENTERS O LLETRES
                while (it != llista_expressio.end()) {
                    istringstream enter(*it);
                    int temp;
                    enter >> temp;
                    tres.afegir_enter_llista(temp);
                    ++it;
                }
                tres.afegir_descripcio("llista");
            }
        }
    }
    return tres;
}


