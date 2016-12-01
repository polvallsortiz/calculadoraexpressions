/** @file Expressio.cc
    @brief Implementació de la classe Expressio de <em>Calculadora d'expressions aritmètiques</em>.
*/

#include "Operacions.hh"

vector<string> Expressio::llegir_expressio(string s) {
    vector<string> llista_expressio;
    s.erase(0, 1);
    s.erase(s.size()-1);
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
    return llista_expressio;
}


void Expressio::evaluar(string expr){
    vector<string> eval = llista_expressio(expr);
    string op = eval[0];
    string l, r;
    l = eval[1];
    r = eval[2];
    evaluar_expressio(op, l, r);
}
vector<int> evaluar_expressio(string op, string left, string right) {

    switch(op){
        case "+":
            int l, r;
            vector<string> vl,vr;
            vl = llegir_expressio(left);
            vr = llegir_expressio(right);
            l = evaluar_expressio(vl[0],vl[1])[0];
            r = evaluar_expressio()[]
            break;
        case default:

            break;
    }
}
