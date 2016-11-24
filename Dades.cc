#include "Dades.hh"

void Dades::afegir_dada_entera(string index, int dada) {
    valor_dades_definides.emplace(index,dada);
}

void Dades::afegir_dada_llista(string index, list<int>& dades){
    valor_dades_definides.emplace(index,dades);
}

bool Dades::etiqueta_list_enters(string etiqueta) {

}

int Dades::valor_enter(string etiqueta) {
    return valor_dades_definides[etiqueta];
}

list Dades::valor_llista(string etiqueta) {
    return valor_llistes_definides[etiqueta];
}