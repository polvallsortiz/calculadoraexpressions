/** @file Dades.cc
    @brief Implementació de la classe Dades
*/


#include "Dades.hh"

Dades::Dades() {
    map_op["+"];
    map_op["-"];
    map_op["cons"];
    map_op["head"];
    map_op["tail"];
    map_op["="];
    map_op["<"];
    map_op["not"];
    map_op["and"];
    map_op["or"];
    map_op["if"];
    op_pref.push_back("+");
    op_pref.push_back("-");
    op_pref.push_back("cons");
    op_pref.push_back("head");
    op_pref.push_back("tail");
    op_pref.push_back("=");
    op_pref.push_back("<");
    op_pref.push_back("not");
    op_pref.push_back("and");
    op_pref.push_back("or");
    op_pref.push_back("if");
}

void Dades::afegir_op(string ref, string exp, list<string> param) {
    Operacio op;
    bool correct = es_correcte(ref,exp,param);
    op.afegir_op(exp,param,correct);
    map_op[ref] = op;
}

void Dades::afegir_dada(string ref, Resultat dada) {
    map_data[ref] = dada;
}

bool Dades::existeix_op(string ref) {
    map<string,Operacio>::iterator it = map_op.find(ref);
    if(it == map_op.end()) return false;
    else return true;
}

bool Dades::existeix_dada(string ref) {
    map<string,Resultat>::iterator it = map_data.find(ref);
    if(it == map_data.end()) return false;
    else return true;
}

string Dades::definir_operacio(string ref, vector<Resultat> param2) {
    string resultat;
    Operacio op = map_op[ref];
    list<string> parametres = op.consultar_parametres();
    //ITERADORS
    list<string>::iterator itp = parametres.begin();
    int itpos = 0;
    resultat = op.consultar_expressio();
    while(itp != parametres.end()) {
        string actual;
        istringstream iss(resultat);
        resultat = "";
        while(iss >> actual) {
            //string antiparentesis = "";
            string parentesis = "";
            /* while(actual[0] == '(') {
                actual.erase(0,1);
                antiparentesis += "(";
            }
             */
            while(actual[(actual.length()-1)] == ')') {
                actual.erase(actual.length()-1);
                parentesis += ")";
            }
            if(actual == *itp) {
                Resultat resactual = param2[itpos];
                if(resactual.consultar_descripcio() == "enter") {
                    int afegir = resactual.consultar_enter();
                    string afegirstr = to_string(afegir);
                    resultat += " " + afegirstr + parentesis;
                    //resultat += " " + antiparentesis + afegirstr + parentesis;
                }
                if(resactual.consultar_descripcio() == "llista") {
                    list<int> temporalint = resactual.consultar_llista();
                    list<int>::iterator itlist = temporalint.begin();
                    int afegir = *itlist;
                    string afegirstr = to_string(afegir);
                    resultat += " (" + afegirstr;
                    //resultat +=" " + antiparentesis + "(" + afegirstr;
                    ++itlist;
                    while(itlist != temporalint.end()) {
                        afegir = *itlist;
                        afegirstr = to_string(afegir);
                        resultat += " " + afegirstr;
                        ++itlist;
                    }
                    resultat += ")" + parentesis;
                }
                if(resactual.consultar_descripcio() == "llistabuida") {
                    resultat += " ()" + parentesis;
                    //resultat += antiparentesis + " ()" + parentesis;
                }
            }
            else {
                resultat += " " + actual + parentesis;
                //resultat += " " + antiparentesis + actual + parentesis;
            }
        }
        ++itp;
        ++itpos;
    }
    resultat.erase(0,1);
    return resultat;
}

Operacio Dades::consultar_operacio(string ref) {
    return map_op[ref];
}

Resultat Dades::consultar_dada(string ref) {
    return map_data[ref];
}

bool Dades::es_correcte(string ref, string s, list<string> param) {
    istringstream iss(s);
    if(param.size() == 1) {
        list<string>::iterator itparametres = param.begin();
        string anormalitzar = *itparametres;
        anormalitzar.erase(0,1);
        anormalitzar.erase(anormalitzar.length()-1);
        param.push_back(anormalitzar);
        param.pop_front();
    }
    string act;
    bool resultat = true;
    while(iss >> act and resultat) {
        while(act[0] == '(') act.erase(0,1);
        while(act.size() != 0 and act[act.length()-1] == ')') act.erase(act.length()-1);
        if(act.length() != 0) {
            if (act[0] == '-' and act.length() != 1) {
                act.erase(0, 1);
            }
            if ((act < "0" or act > "9") and act != ref) {
                map<string, Operacio>::iterator itops = map_op.find(act);
                list<string>::iterator itparam = param.begin();
                if (itops == map_op.end()) {
                    bool trobat = false;
                    while (not trobat and itparam != param.end()) {
                        if(*itparam == act) trobat = true;
                        else ++itparam;
                    }
                    if (itparam == param.end()) resultat = false;
                }
            }
        }
    }
    return resultat;
}

bool Dades::es_predefinida(string s) {
    list<string>::iterator it = op_pref.begin();
    while (it != op_pref.end()) {
        if (*it == s) return true;
        ++it;
    }
    return false;
}

void Dades::finalitzar() {
    cout << "Variables:" << endl;
    map<string,Resultat>::iterator itdades = map_data.begin();
    while(itdades != map_data.end()) {
        cout << itdades->first << " ";
        Resultat res = itdades->second;
        if(res.consultar_descripcio() == "llistabuida") cout << "()" << endl;
        if(res.consultar_descripcio() == "llista") {
            list<int> llista = res.consultar_llista();
            cout << "(";
            list<int>::iterator itllista = llista.begin();
            cout << *itllista;
            ++itllista;
            while(itllista != llista.end()) {
                cout << " " << *itllista;
                ++itllista;
            }
            cout << ")" << endl;
        }
        if(res.consultar_descripcio() == "enter") cout << res.consultar_enter() << endl;
        ++itdades;
    }
    cout << "Operacions:" << endl;
    map<string,Operacio>::iterator itops;
    for(itops = map_op.begin(); itops != map_op.end(); ++itops) {
        if(not es_predefinida(itops->first)) {
            cout << itops->first << " #";
            Operacio op = itops->second;
            cout << op.consultar_numero_parametres() << endl;
        }
    }
}