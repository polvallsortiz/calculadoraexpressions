/** @file Expressio.cc
    @brief Implementació de la classe Expressio de <em>Calculadora d'expressions aritmètiques</em>.
*/

#include "Expressio.hh"

//FUNCIONS PRÒPIES
bool llista(string s) {
    if(s[0] == '(' and s[s.length()-1] == ')')  return true;
    else return false;
}

bool llista_buida(string s) {
    if(s[0] == '(' and s[1] == ')') return true;
    else return false;
}

bool llista_parent(string s) {
    if(s[0] == '(' and s[s.length()-1] == ')') return true;
    else return false;
}

int num_paraules(string s){
    int resultat = 1;
    for(int i = 0; i < s.length(); ++i) {
        if(s[i] == ' ') ++resultat;
    }
    return resultat;
}

Expressio::Expressio() {

}

void Expressio::inicialitzar(string comanda,Dades& dat) {
    list<string> llista;
    string condicio = llegir_expressio(comanda,llista);
    Resultat res;
    if(condicio == "simple") { //ATOM
        if(comanda[0] == '(') { //LLISTA
            string act = *llista.begin();
            if(llista.size() == 1 and act[1] == ')') res.afegir_descripcio("llistabuida");
            else { //LLISTA UN ELEMENT O LLISTA DEFINIDA O OPERACIO SENSE PARAMETRES
                act.erase(0, 1);
                act.erase(act.length() - 1);
                if (dat.existeix_op(act)) {
                    Operacio actualop = dat.consultar_operacio(act);
                    if(actualop.consultar_validesa() and actualop.consultar_numero_parametres() == 0) {
                        string perevaluar = actualop.consultar_expressio();
                        list <string> llistaops;
                        llegir_expressio(perevaluar, llistaops);
                        res = evaluar(llistaops, dat);
                    }
                } else {
                    act = "(" + act + ")";
                    if (dat.existeix_dada(act)) {
                        res = dat.consultar_dada(act);
                    } else {
                        act.erase(0, 1);
                        act.erase(act.length() - 1);
                        if (act[0] == '(') res.afegir_descripcio("indefinit");
                        else {
                            list<int> llistatemp;
                            istringstream buff(act);
                            int ent;
                            buff >> ent;
                            llistatemp.push_back(ent);
                            res.afegir_llista(llistatemp);
                            res.afegir_descripcio("llista");
                        }
                    }
                }
            }
        }
        else { //ENTER O DADA DEFINIDA DIRECTA
            string actual = *llista.begin();
            bool negatiu = false;
            if(actual[0] == '-') {
                negatiu = true;
                actual.erase(0,1);
            }
            if(actual[0] < '0' or actual[0] > '9') {
                if(dat.existeix_dada(actual)) res = dat.consultar_dada(actual);
            }
            else {
                if(negatiu) actual = "-" + actual;
                res.afegir_descripcio("enter");
                istringstream iss(*llista.begin());
                int temp;
                iss >> temp;
                res.afegir_enter_bool(temp);
            }
        }
    }
    else{
        if(condicio == "opnormal") res = evaluar(llista,dat);
        if(condicio == "llistaperevaluar") {
            list<int> definitiva;
            bool indefinit = false;
            list<string>::iterator it  = llista.begin();
            while(it != llista.end() and not indefinit) {
                string actual = *it;
                list<string> llistal;
                llegir_expressio(actual,llistal);
                Resultat res1 = evaluar(llistal,dat);
                if(res1.consultar_descripcio() == "enter") definitiva.push_back(res1.consultar_enter());
                else indefinit = true;
                ++it;
                res.afegir_descripcio("no");
            }
            if(indefinit) cout << "indefinit" << endl;
            else {
                list<int>::iterator iti = definitiva.begin();
                cout << "(" << *iti;
                ++iti;
                while(iti != definitiva.end()) {
                    cout << " " << *iti;
                    ++iti;
                }
                cout << ")" << endl;
            }
        }
        if(condicio == "llistaints") {
            res.afegir_descripcio("no");
            list<string>::iterator itb = llista.begin();
            cout << "(" << *itb;
            ++itb;
            while(itb != llista.end()) {
                cout << " " << *itb;
                ++itb;
            }
            cout << ")" << endl;
        }
    }
    //  ^                                 |
    //  | DECLARACIONS I CASOS ESPECIALS  V EVALUACIÓ DEL RESULTAT
    if(res.consultar_descripcio() == "enter" or res.consultar_descripcio() == "llista" or res.consultar_descripcio() == "indefinit" or res.consultar_descripcio() == "llistabuida") {
        if (res.consultar_descripcio() == "enter") cout << res.consultar_enter() << endl;
        if (res.consultar_descripcio() == "llista") {
            if (res.consultar_llista().size() == 0) cout << "()" << endl;
            else {
                list<int> listtemp;
                listtemp = res.consultar_llista();
                list<int>::iterator it = listtemp.begin();
                cout << "(" << *it;
                if (listtemp.size() != 0) {
                    ++it;
                    while (it != listtemp.end()) {
                        cout << " " << *it;
                        ++it;
                    }
                }
                cout << ")" << endl;
            }
        }
        if (res.consultar_descripcio() == "indefinit") {
            cout << "indefinit" << endl;
        }
        if(res.consultar_descripcio() == "llistabuida") cout << "()" << endl;
    }
    else { //DEFINE DE OP
        if(res.consultar_descripcio() != "no") cout << res.consultar_descripcio() << " #" << res.consultar_enter() << endl;
    }
}

string Expressio::llegir_expressio(string s, list<string>& llista_expressio){
    string aretornar;
    if(num_paraules(s) == 1){
        llista_expressio.push_back(s);
        aretornar = "simple";
    }
    else {
        bool par = false;
        if(s[0] == '(') {
            par = true;
            s.erase(0,1);
            while(s[s.length()-1] != ')') {
                s.erase(s.length()-1);
            }
            s.erase(s.length()-1);
        }
        if(s[0] >= '0' and s[0] <= '9') {
            if(par) aretornar = "llistaperevaluar";
            else aretornar = "llistaints";
        }
        else {
            if(s[0] == '(') aretornar = "llistaperevaluar";
            else aretornar = "opnormal";
        }
        istringstream iss(s);
        string frag = "";
        string tmp = "";
        int c = 0;
        while (iss >> tmp) {
            for (int i = 0; tmp[i] == '('; i++)c++;
            for (int i = tmp.size() - 1; tmp[i] == ')'; i--)c--;
            frag += (frag == "" ? "" : " ") + tmp;
            if (c == 0) {
                llista_expressio.push_back(frag);
                frag = "";
            }
        }
    }
    return aretornar;
}


Resultat Expressio::evaluar(list<string> llista_expressio, Dades& dat) {
    list<string>::iterator it = llista_expressio.begin();
    string op = *it;
    Resultat tres;
    if(dat.es_predefinida(op)) {
        if (op == "+") {
            if(llista_expressio.size() == 3) {
                ++it;
                string l = *it;
                list<string> llistal;
                llegir_expressio(l, llistal);
                Resultat lres = evaluar(llistal, dat);
                if(lres.consultar_descripcio() == "enter") {
                    ++it;
                    string r = *it;
                    list<string> llistar;
                    llegir_expressio(r, llistar);
                    Resultat rres = evaluar(llistar, dat);
                    if(rres.consultar_descripcio() == "enter") {
                        tres.afegir_enter_bool(lres.consultar_enter() + rres.consultar_enter());
                        tres.afegir_descripcio("enter");
                    }
                }
            }
        }
        if (op == "-") {
            if(llista_expressio.size() == 2) {
                ++it;
                string l = *it;
                list<string> llistal;
                llegir_expressio(l, llistal);
                Resultat lres = evaluar(llistal, dat);
                if(lres.consultar_descripcio() == "enter") {
                    tres.afegir_enter_bool(-lres.consultar_enter());
                    tres.afegir_descripcio("enter");
                }
            }
        }
        if (op == "cons") {
            if(llista_expressio.size() == 3) {
                ++it;
                string l = *it;
                list<string> llistal;
                llegir_expressio(l, llistal);
                Resultat lres = evaluar(llistal, dat);
                if(lres.consultar_descripcio() == "enter") {
                    ++it;
                    string r = *it;
                    list<string> llistar;
                    llegir_expressio(r, llistar);
                    Resultat rres = evaluar(llistar, dat);
                    if(rres.consultar_descripcio() == "llista") {
                        tres.afegir_llista(rres.consultar_llista());
                        tres.afegir_enter_llista_davanter(lres.consultar_enter());
                        tres.afegir_descripcio("llista");
                    }
                    if(rres.consultar_descripcio() == "llistabuida") {
                        tres.afegir_enter_llista_davanter(lres.consultar_enter());
                        tres.afegir_descripcio("llista");
                    }
                }
            }
        }
        if (op == "head") {
            if(llista_expressio.size() == 2) {
                ++it;
                string l = *it;
                list<string> llistal;
                string condicio = llegir_expressio(l, llistal);
                Resultat lres;
                if(condicio == "llistaperevaluar") {
                    list<string> llistaeval;
                    llegir_expressio(l,llistaeval);
                    lres = evaluar(llistaeval,dat);
                }
                else lres = evaluar(llistal, dat);
                if (lres.consultar_descripcio() == "llista") {
                    tres.afegir_enter_bool(lres.consultar_top());
                    tres.afegir_descripcio("enter");
                }
            }
        }
        if (op == "tail") {
            if(llista_expressio.size() == 2) {
                ++it;
                string l = *it;
                list<string> llistal;
                llegir_expressio(l, llistal);
                Resultat lres = evaluar(llistal, dat);
                if(lres.consultar_descripcio() == "llista") {
                    tres.afegir_llista(lres.consultar_llista());
                    if(tres.consultar_llista().size() != 0) {
                        tres.esborrar_enter_llista();
                        if (tres.consultar_llista().size() == 0) tres.afegir_descripcio("llistabuida");
                        else tres.afegir_descripcio("llista");
                    }
                }
            }
        }
        if (op == "=") {
            if(llista_expressio.size() == 3) {
                ++it;
                string l = *it;
                list<string> llistal;
                llegir_expressio(l, llistal);
                Resultat lres = evaluar(llistal, dat);
                ++it;
                string r = *it;
                list<string> llistar;
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
                    if (lres.consultar_descripcio() == "llista") {
                        if(rres.consultar_descripcio() == "llista") {
                            if (lres.consultar_llista() == rres.consultar_llista()) {
                                tres.afegir_enter_bool(1);
                                tres.afegir_descripcio("enter");
                            } else {
                                tres.afegir_enter_bool(0);
                                tres.afegir_descripcio("enter");
                            }
                        }
                        if(rres.consultar_descripcio() == "llistabuida") {
                            tres.afegir_enter_bool(0);
                            tres.afegir_descripcio("enter");
                        }
                    }
                    if(lres.consultar_descripcio() == "llistabuida") {
                        if(rres.consultar_descripcio() == "llista") {
                            tres.afegir_enter_bool(0);
                            tres.afegir_descripcio("enter");
                        }
                        if(rres.consultar_descripcio() == "llistabuida") {
                            tres.afegir_enter_bool(1);
                            tres.afegir_descripcio("enter");
                        }
                    }
                }
            }
        }
        if (op == "<") {
            if(llista_expressio.size() == 3) {
                ++it;
                string l = *it;
                list<string> llistal;
                llegir_expressio(l, llistal);
                Resultat lres = evaluar(llistal, dat);
                ++it;
                string r = *it;
                list<string> llistar;
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
                }
                if (lres.consultar_descripcio() == "llista") {
                    if(rres.consultar_descripcio() == "llista") {
                        if (lres.consultar_llista() < rres.consultar_llista()) {
                            tres.afegir_enter_bool(1);
                            tres.afegir_descripcio("enter");
                        } else {
                            tres.afegir_enter_bool(0);
                            tres.afegir_descripcio("enter");
                        }
                    }
                    if(rres.consultar_descripcio() == "llistabuida") {
                        tres.afegir_enter_bool(0);
                        tres.afegir_descripcio("enter");
                    }
                }
                if(lres.consultar_descripcio() == "llistabuida") {
                    if(rres.consultar_descripcio() == "llistabuida") {
                        tres.afegir_enter_bool(0);
                        tres.afegir_descripcio("enter");
                    }
                    if(rres.consultar_descripcio() == "llista") {
                        tres.afegir_enter_bool(1);
                        tres.afegir_descripcio("enter");
                    }
                }
            }
        }
        if (op == "not") {
            if(llista_expressio.size() == 2) {
                ++it;
                string l = *it;
                list<string> llistal;
                llegir_expressio(l, llistal);
                Resultat lres = evaluar(llistal, dat);
                if (lres.es_boolea()) {
                    if (lres.consultar_enter() == 0) tres.afegir_enter_bool(1);
                    else tres.afegir_enter_bool(0);
                    tres.afegir_descripcio("enter");
                }
            }
        }
        if (op == "and") {
            if(llista_expressio.size() == 3) {
                ++it;
                string l = *it;
                list<string> llistal;
                llegir_expressio(l, llistal);
                Resultat lres = evaluar(llistal, dat);
                if(lres.es_boolea()) {
                    ++it;
                    string r = *it;
                    list<string> llistar;
                    llegir_expressio(r, llistar);
                    Resultat rres = evaluar(llistar, dat);
                    if (rres.es_boolea()) {
                        if (lres.consultar_enter() == 1 and rres.consultar_enter() == 1) tres.afegir_enter_bool(1);
                        else tres.afegir_enter_bool(0);
                        tres.afegir_descripcio("enter");
                    }
                }
            }
        }
        if (op == "or") {
            if(llista_expressio.size() == 3) {
                ++it;
                string l = *it;
                list<string> llistal;
                llegir_expressio(l, llistal);
                Resultat lres = evaluar(llistal, dat);
                if (lres.es_boolea()) {
                    ++it;
                    string r = *it;
                    list<string> llistar;
                    llegir_expressio(r, llistar);
                    Resultat rres = evaluar(llistar, dat);
                    if (rres.es_boolea()) {
                        if (lres.consultar_enter() == 1 or rres.consultar_enter() == 1) tres.afegir_enter_bool(1);
                        else tres.afegir_enter_bool(0);
                        tres.afegir_descripcio("enter");
                    }
                }
            }
        }
        if (op == "if") {
            if(llista_expressio.size() == 4) {
                ++it;
                string x = *it;
                list<string> llistax;
                llegir_expressio(x, llistax);
                Resultat
                xres = evaluar(llistax, dat);
                ++it;
                if (xres.es_boolea()) {
                    if (xres.consultar_enter() == 1) {
                        string y = *it;
                        list<string> llistay;
                        llegir_expressio(y, llistay);
                        Resultat yres = evaluar(llistay, dat);
                        if (yres.consultar_descripcio() == "llista") {
                            tres.afegir_descripcio("llista");
                            tres.afegir_llista(yres.consultar_llista());
                        }
                        if(yres.consultar_descripcio() == "llistabuida") {
                            tres.afegir_descripcio("llistabuida");
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
                        if(zres.consultar_descripcio() == "llistabuida") {
                            tres.afegir_descripcio("llistabuida");
                        }
                        if (zres.consultar_descripcio() == "enter") {
                            tres.afegir_descripcio("enter");
                            tres.afegir_enter_bool(zres.consultar_enter());
                        }
                    }
                }
            }
        }
        if (op == "define") {
            if(llista_expressio.size() > 2) {
                ++it;
                string ref = *it;
                ++it;
                if (it == (--llista_expressio.end())) { //DEFINE DE ENTER/LLISTA ENTERS
                    string ent = *it;
                    list<string> llistaent;
                    llegir_expressio(ent, llistaent);
                    tres = evaluar(llistaent, dat);
                    if(tres.consultar_descripcio() != "indefinit") dat.afegir_dada(ref, tres);
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
                    if (tres.consultar_descripcio() == "llistabuida") cout << "()" << endl;
                    if (tres.consultar_descripcio() == "indefinit") cout << "indefinit" << endl;
                    tres.afegir_descripcio("no");
                } else { //DEFINE DE OPERACIÓ
                    string param = *it;
                    list <string> llistaparam;
                    if(param != "()") llegir_expressio(param, llistaparam);
                    int numparam = llistaparam.size();
                    ++it;
                    string exp = *it;
                    dat.afegir_op(ref, exp, llistaparam);
                    tres.afegir_descripcio(ref);
                    list<string>::iterator excepcio = llistaparam.begin();
                    tres.afegir_enter_bool(numparam);
                }
            }
        }

    }
    else { //O OP DEFINIDA, DADA DEFINIDA, ENTER SOL, LLISTA D'ENTERS (BUIDA O NO)
        if (dat.existeix_op(op)) { //EXISTEIX OP A DADES
            Operacio operacio = dat.consultar_operacio(op);
            if(operacio.consultar_validesa()) {
                int numparametres = operacio.consultar_numero_parametres();
                if (llista_expressio.size() == (numparametres + 1)) {
                    bool indefinida = false;
                    vector<Resultat> vec_parametres;
                    while (numparametres != 0 and not indefinida) {
                        ++it;
                        list <string> llistal;
                        llegir_expressio(*it, llistal);
                        Resultat lres = evaluar(llistal, dat);
                        vec_parametres.push_back(lres);
                        /*CODI EXCEPCIONAL
                        if(perafegir.consultar_descripcio() == "llista") {
                            Resultat excep;
                            excep.afegir_llista(perafegir.consultar_llista());
                            excep.afegir_descripcio("llista");
                            llista_parametres.push_back(excep);
                        }
                        if(perafegir.consultar_descripcio() == "llistabuida") {
                            Resultat excep;
                            excep.afegir_descripcio("llistabuida");
                            llista_parametres.push_back(excep);
                        }
                        if(perafegir.consultar_descripcio() == "enter") {
                            Resultat excep;
                            excep.afegir_enter_bool(perafegir.consultar_enter());
                            excep.afegir_descripcio("enter");
                            llista_parametres.push_back(excep);
                        }
                         */
                        //CODI QUE HAURIA DE FUNCIONAR
                        //llista_parametres.push_back(lres);
                        --numparametres;
                    }
                    if (not indefinida) {
                        string post = dat.definir_operacio(op, vec_parametres);
                        list <string> llistapost;
                        llegir_expressio(post, llistapost);
                        tres = evaluar(llistapost, dat);
                    }
                }
            }
        }
        else {
            bool negatiu = false;
            if(op[0] == '-') {
                op.erase(0,1);
                negatiu = true;
            }
            if((op[0] < '0' or op[0] > '9') and op != "()") {
                if (dat.existeix_dada(op)) tres = dat.consultar_dada(op); //A DADES DEFINIDES
                else {
                    if (op[0] == '(' and op[op.length() - 1] == ')') { //RETORNA LLISTA '(' ... ')'
                        op.erase(0, 1);
                        op.erase(op.length() - 1);
                        list<string> llistar;
                        llegir_expressio(op, llistar);
                        Resultat rres = evaluar(llistar, dat);
                        if (rres.consultar_descripcio() == "llista") {
                            tres.afegir_llista(rres.consultar_llista());
                            tres.afegir_descripcio("llista");
                        }
                        if (rres.consultar_descripcio() == "enter") {
                            tres.afegir_enter_llista_davanter(rres.consultar_enter());
                            tres.afegir_descripcio("llista");
                        }
                    }
                }
            }
            else { //ALTRAMENT
                if(negatiu) op = "-" + op;
                if(llista(op)) { //LLISTA
                    if(llista_buida(op)) tres.afegir_descripcio("llistabuida"); //LLISTABUIDA
                    else {
                        if(llista_parent(op)) {
                            op.erase(0, 1); //Eliminem '('
                            op.erase(op.length() - 1); //Eliminem ')'
                        }
                        istringstream buffer(op);
                        int temp;
                        list<int> templist;
                        while(buffer >> temp) {
                            templist.push_back(temp);
                        }
                        tres.afegir_llista(templist);
                        tres.afegir_descripcio("llista");
                    }
                }
                else { //ENTER O LLISTA
                    if(it == --llista_expressio.end()) { //ENTER
                        istringstream buffer(op);
                        int temp;
                        buffer >> temp;
                        tres.afegir_enter_bool(temp);
                        tres.afegir_descripcio("enter");
                    }
                    else {
                        list<int> llistatemp;
                        while(it != llista_expressio.end()) {
                            list<string> lintres;
                            llegir_expressio(*it,lintres);
                            Resultat intres = evaluar(lintres,dat);
                            llistatemp.push_back(intres.consultar_enter());
                            ++it;
                        }
                        tres.afegir_descripcio("llista");
                        tres.afegir_llista(llistatemp);
                    }
                }
            }
        }
    }
    return tres;
}


