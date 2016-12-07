//
// Created by Pol Valls Ortiz on 24/11/2016.
//

#include <iostream>
#include <string>
#include <list>
#include <map>
#include <sstream>
#include <vector>
using namespace std;

struct Resultat {
    vector<int> llista;
    int resultat;
    string desc;
};

void llegir_expressio(string s, list<string>& llista_expressio) {
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
        llegir_expressio(l.llistal);
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
        lres.llista = lres.llista.pop_front();
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
        return tres;
    }
    //TOTES LES OP'S
    else {
            Resultat tres;
            istringstream stoi(*it);
            int res;
            stoi >> res;
            tres.resultat = res;
        return tres;
    }
}

int main() {
    list<string> llista;
    string frase;
    getline(cin,frase);
    llegir_expressio(frase,llista);
    Resultat res;
    res = evaluar(llista);
    cout << res.resultat << endl;

}

