/** @file Expressio.cc
    @brief Implementació de la classe Expressio de <em>Calculadora d'expressions aritmètiques</em>.
*/

#include "Operacions.hh"

void llegir_expressio(string s) {
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


void Expressio::evaluar(){
    list<string>::iterator it = llista_expressio.begin();
    string op = *it;
    if(op == "+" or op == "cons" or op == "=" or op == "<" or op == "and"  or op == "or") {
        string left,right;
        ++it;
        left = *it;
        ++it;
        right = *it;
        if(it != llista_expressio.end()) cout << "indefinit" << endl;
        else evaluar_dob(op,left,right);
    }
    if(op == "-" or op == "head" or op == "tail" or op == "not") {
        string uni;
        ++it;
        uni = *it;
        if(it != llista_expressio.end()) cout << "indefinit" << endl;
        else evaluar_uni(op,uni);
    }
}



list<int> evaluar_dob(string op, string l, string r) {
    switch(op){
        case "+":
            list <string> sub_expressio;
            llegir_expressio(l);

            break;
    }
}
