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
    
    //VER SE A CAPACIDADE PERMITE ADICIONAR O FILME
    if (novoCatalogo.catalogo.size() < size_t(novoCatalogo.capacidade)) {

        //VER SE O FILME EXISTE ANTES DE ADICIONAR
        for (const Filme& f : novoCatalogo.catalogo) {
            if (f == filme) {
                cout << "Filme ja existe no catalogo: " << filme.titulo << endl;
                return novoCatalogo;
            }
        }

        //ADICIONA O FILME AO CATALOGO
        novoCatalogo.catalogo.push_back(filme);
        cout << "Filme adicionado: " << filme.titulo << endl;
    } else {
        cout << "Capacidade maxima atingida." << endl;
    }
    
    return novoCatalogo; 
}

//-----------------SOBRECARGA DO OPERADOR - -----------------
CatalogoFilmes CatalogoFilmes::operator - (const Filme& filme) {
    CatalogoFilmes novoCatalogo = *this; 

    //VER SE O FILME EXISTE ANTES DE REMOVER
    for (size_t i = 0; i < novoCatalogo.catalogo.size(); ++i) {
        if (novoCatalogo.catalogo[i] == filme) {

            //REMOVER O FILME DO CATALOGO
            novoCatalogo.catalogo.erase(novoCatalogo.catalogo.begin() + i);
            cout << "Filme removido: " << filme.titulo << endl;
            return novoCatalogo;
        }
    }

    cout << "Filme nao encontrado no catalogo: " << filme.titulo << endl;
    return novoCatalogo; 
}

//-----------------SOBRECARGA DO OPERADOR == -----------------
bool operator == (const Filme& f1, const Filme& f2) {
    return (f1.titulo == f2.titulo);
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
        //Apagar o arquivpo para evitar duplicatas
        arquivo.clear();
        arquivo.seekp(0, ios::beg); //Voltar para o inicio do arquivo

        // escreve cada filme do catalogo atualizado no arquivo
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
