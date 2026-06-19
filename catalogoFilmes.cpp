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

//-----------------SOBRECARGA DO OPERADOR [] - BUSCA POR DIRETOR -----------------
vector<Filme> CatalogoFilmes::operator[](const string& diretor) {
    vector<Filme> filmesDoDiretor;

    for (const Filme& filme : catalogo) {
        if (filme.diretor == diretor) {
            filmesDoDiretor.push_back(filme);
        }
    }

    return filmesDoDiretor;
}

//----------- IMPRESSOESÃO DO CATALOGO E FILME -----------------

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
    os << "Titulo: " << filme.titulo << endl;
    os << "Diretor: " << filme.diretor << endl;
    os << "Ano: " << filme.anoLancamento << endl;
    os << "Nota: " << filme.notaMedia << endl;
    return os;
}

istream& operator>>(istream& is, Filme& filme) {
    string lixo;
    
    if (is >> lixo) { // Consome a palavra "Titulo:"
        is.ignore(); // Ignora o espaço em branco depois do ":"
        getline(is, filme.titulo);
    }
    
    if (is >> lixo) { // Consome a palavra "Diretor:"
        is.ignore();
        getline(is, filme.diretor);
    }
    
    if (is >> lixo) { // Consome a palavra "Ano:"
        is.ignore();
        is >> filme.anoLancamento;
    }
    
    if (is >> lixo) { // Consome a palavra "Nota:"
        is.ignore();
        is >> filme.notaMedia;
    }
    
    is.ignore(); // Limpa o \n

    return is;
}

ostream& operator<<(ostream& os, const CatalogoFilmes& catalogo) {
    for (const Filme& filme : catalogo.catalogo) {
        os << filme << endl;
    }
    return os;
}
