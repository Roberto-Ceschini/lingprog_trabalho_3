#include "catalogoFilmes.h"
#include <fstream>
#include <iostream>

using namespace std;

//-----------------CONSTRUTOR E DESTRUTOR-----------------

CatalogoFilmes::CatalogoFilmes(int _capacidade) {
    capacidade = _capacidade;
    carregarArquivo();
}

CatalogoFilmes::~CatalogoFilmes() {
    salvarArquivo();
}

//-----------------SOBRECARGA DO OPERADOR + -----------------
CatalogoFilmes CatalogoFilmes::operator + (const Filme& filme) {
    CatalogoFilmes novoCatalogo = *this; 
    
    if (novoCatalogo.catalogo.size() < size_t(novoCatalogo.capacidade)) {
        novoCatalogo.catalogo.push_back(filme);
        cout << "Filme adicionado: " << filme.titulo << endl;
    } else {
        cout << "Capacidade maxima atingida." << endl;
    }
    
    return novoCatalogo; 
}


//------------ARQUIVOS, OSTREAM E ISTREAM----------------

void CatalogoFilmes::carregarArquivo(){
    ifstream arquivo(nomeArquivo);
    if (arquivo.is_open()) {
        Filme filme;
        while (arquivo >> filme) {
            catalogo.push_back(filme);
        }
        arquivo.close();
    } else {
        cout << "Nao foi possivel abrir o arquivo: " << nomeArquivo << endl;
    }
}

void CatalogoFilmes::salvarArquivo(){
    ofstream arquivo(nomeArquivo);
    if (arquivo.is_open()) {
        for (const Filme& filme : catalogo) {
            arquivo << filme << endl;
        }
        arquivo.close();
    } else {
        cout << "Nao foi possivel abrir o arquivo: " << nomeArquivo << endl;
    }
}



//-----------------SOBRECARGA DE OPERADORES << E >> -----------------
ostream& operator<<(ostream& os, const Filme& filme) {

    os << filme.titulo << endl;
    os << filme.diretor << endl;
    os << filme.anoLancamento << endl;
    os << filme.notaMedia << endl;
    return os;
}

istream& operator>>(istream& is, Filme& filme) {

    getline(is, filme.titulo);
    getline(is, filme.diretor);
    is >> filme.anoLancamento;
    is >> filme.notaMedia;
     //limpa o caractere de nova linha 
    
    return is;
}

ostream& operator<<(ostream& os, const CatalogoFilmes& catalogo) {
    for (const Filme& filme : catalogo.catalogo) {
        os << filme << endl;
    }
    return os;
}
