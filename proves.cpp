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
    bool indefinit;
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

Resultat evaluar(string op, string left, string right) {
    if(op == "+") {
        ++it;
        string l = *it;
        list<string> llistal;
        llegir_expressio(l,llistal);
        string lop,lleft,lrigth;
        ++it;
        string r = *it;

    }
    if (op == "+" or op == "cons" or op == "=" or op == "<" or op == "and" or op == "or") {


    }
    if (op == "-" or op == "head" or op == "tail" or op == "not") {

    }
    else {

    }
}

int main() {
    list<string> llista;
    string frase;
    getline(cin,frase);
    llegir_expressio(frase,llista);
    Resultat res;
    res = evaluar(llista);

}

