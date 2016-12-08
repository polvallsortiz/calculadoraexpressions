/** @file Expressio.cc
    @brief Implementació de la classe Expressio de <em>Calculadora d'expressions aritmètiques</em>.
*/

#include "Expressio.hh"

void inicialitzar(string comanda) {
    list<string> llista;
    llegir_expressio(comanda,llista);
    Resultat res = evaluar(llista);
    if(res.desc == "bool") {
        if(res.resultat == 1) {
            cout << res.resultat << " " << "TRUE" << endl;
        }
        else {
            cout << res.resultat << " " << "FALSE" << endl;
        }
    }
    if(res.desc == "enter") cout << res.resultat << " " << "ENTER" << endl;
    if(res.desc == "llista") {
        list<int>::iterator it = res.llista.begin();
        while(it != res.llista.end()) {
            cout << *it << " ";
            ++it;
        }
        cout << endl << "LLISTA" << endl;
    }
    if(res.desc == "indefinit") {
        cout << "******** INDEFINIT ********" << endl;
    }
}


void llegir_expressio(string s, list<string>& llista_expressio){
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


Resultat evaluar(list<string> llista_expressio) {
    list<string>::iterator it = llista_expressio.begin();
    string op = *it;
    if(op == "+") {
        ++it;
        string l = *it;
        cerr << l << endl;
        list<string> llistal;
        llegir_expressio(l,llistal);
        Resultat lres = evaluar(llistal);
        ++it;
        string r = *it;
        list<string> llistar;
        llegir_expressio(r,llistar);
        Resultat rres = evaluar(llistar);
        Resultat tres;
        tres.resultat = lres.resultat + rres.resultat;
        tres.desc = "enter";
        return tres;
    }
    if(op == "-") {
        ++it;
        string l = *it;
        list <string> llistal;
        llegir_expressio(l,llistal);
        Resultat lres = evaluar(llistal);
        lres.resultat = -lres.resultat;
        lres.desc = "enter";
        return lres;
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
        list<int> treslist;
        treslist = rres.llista;
        treslist.push_back(lres.resultat);
        Resultat tres;
        tres.llista = treslist;
        tres.desc = "llista";
        return tres;
    }
    if(op == "head") {
        ++it;
        string l = *it;
        list<string> llistal;
        llegir_expressio(l,llistal);
        Resultat lres = evaluar(llistal);
        lres.resultat = lres.llista.front();
        lres.desc = "enter";
        return lres;
    }
    if(op == "tail") {
        ++it;
        string l = *it;
        list<string> llistal;
        llegir_expressio(l,llistal);
        Resultat lres = evaluar(llistal);
        lres.llista.pop_front();
        lres.desc = "llista";
        return lres;
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
        Resultat tres;
        if(lres.desc == "enter" and rres.desc == "enter") {
            if(lres.resultat == rres.resultat) {
                tres.resultat = 1;
                tres.desc = "bool";
            }
            else {
                tres.resultat = 0;
                tres.desc = "bool";
            }

        }
        else {
            if(lres.desc == "llista" and rres.desc == "llista") {
                if(lres.llista == rres.llista) {
                    tres.resultat = 1;
                    tres.desc = "bool";
                }
                else {
                    tres.resultat = 0;
                    tres.desc = "bool";
                }

            }
            else {
                if(lres.desc == "bool" and rres.desc == "bool") {
                    if(lres.resultat == rres.resultat) {
                        tres.resultat = 1;
                        tres.desc = "bool";
                    }
                    else {
                        tres.resultat = 0;
                        tres.desc = "bool";
                    }
                }
                else {
                    tres.desc = "indefinit";
                }
            }
        }
        return tres;
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
        Resultat tres;
        if(lres.desc == "enter" and rres.desc == "enter") {
            if(lres.resultat < rres.resultat) {
                tres.resultat = 1;
                tres.desc = "bool";
            }
            else {
                tres.resultat = 0;
                tres.desc = "bool";
            }

        }
        else {
            tres.desc = "indefinit";
        }
        return tres;
    }
    if(op == "not") {
        ++it;
        string l = *it;
        list<string> llistal;
        llegir_expressio(l,llistal);
        Resultat lres = evaluar(llistal);
        Resultat tres;
        if(lres.desc == "bool") {
            if(lres.resultat == 0) tres.resultat = 1;
            else tres.resultat = 0;
            tres.desc = "bool";
        }
        else tres.desc = "indefinit";
        return tres;
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
        Resultat tres;
        if(lres.desc == "bool" and rres.desc == "bool") {
            if(lres.resultat == 1 and rres.resultat == 1) {
                tres.resultat = 1;
                tres.desc = "bool";
            }
            else {
                tres.resultat = 0;
                tres.desc = "bool";
            }
        }
        else tres.desc = "indefinit";
        return tres;
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
        Resultat tres;
        if(lres.desc == "bool" and rres.desc == "bool") {
            if(lres.resultat == 1 or rres.resultat == 1) {
                tres.resultat = 1;
                tres.desc = "bool";
            }
            else {
                tres.resultat = 0;
                tres.desc = "bool";
            }
        }
        else tres.desc = "indefinit";
        return tres;
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
        Resultat tres;
        if(xres.desc == "bool") {
            if(xres.resultat == 0) {
                if(yres.desc == "llista") {
                    tres.desc = "llista";
                    tres.llista = yres.llista;
                }
                if(yres.desc == "enter") {
                    tres.desc = "enter";
                    tres.resultat = yres.resultat;
                }
                if(yres.desc == "bool") {
                    tres.desc = "bool";
                    tres.resultat = yres.resultat;
                }
            }
            else {
                if(zres.desc == "llista") {
                    tres.desc = "llista";
                    tres.llista = zres.llista;
                }
                if(zres.desc == "enter") {
                    tres.desc = "enter";
                    tres.resultat = zres.resultat;
                }
                if(zres.desc == "bool") {
                    tres.desc = "bool";
                    tres.resultat = zres.resultat;
                }
            }
        }
        else tres.desc = "indefinit";
        return tres;
    }
    else {
        if(llista_expressio.size() == 1) { //ENTER SOL
            Resultat tres;
            istringstream enter(*it);
            enter >> tres.resultat;
            tres.desc = "enter";
            return tres;
        }
        else { //LLISTA
            Resultat tres;
            while(it != llista_expressio.end()) {
                istringstream enter(*it);
                int temp;
                enter >> temp;
                tres.llista.push_back(temp);
                ++it;
            }
            return tres;
        }
    }
}
