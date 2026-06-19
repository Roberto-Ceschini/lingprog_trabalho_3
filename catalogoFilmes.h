

#ifndef CATALOGOFILMES_H
#define CATALOGOFILMES_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct Filme{
    string titulo;
    string diretor;
    int anoLancamento;
    double notaMedia;
};

class CatalogoFilmes{

    friend ostream& operator<<(ostream&, const CatalogoFilmes&);
    friend ostream& operator<<(ostream&, const Filme&);
    friend istream& operator>>(istream&, Filme&);
    friend bool operator==(const Filme&, const Filme&);

    public:
        CatalogoFilmes(int);
        ~CatalogoFilmes(); //coloquei para lembrar de usar o destrutor para salvar o catalogo ao fechar o programa
        
        CatalogoFilmes operator + (const Filme&);
        CatalogoFilmes operator - (const Filme&);
        vector <Filme> operator [] (const string& diretor);

    private:

        vector<Filme> catalogo;
        int capacidade;

        string nomeArquivo = "catalogo.txt";

        void carregarArquivo();
        void salvarArquivo();
};

bool operator == (const Filme&, const Filme&); //o c++reserva o primeiro operador para o proprio objeto da classe, mas como o filme é uma structm, precisamos declarar a função fora da classe, e como ela é amiga da classe, ela tem acesso aos atributos privados da classe, o que nos permite comparar os filmes pelo titulo.

//perguntar pq isso da certo??
ostream& operator<<(ostream& os, const Filme& filme);
istream& operator>>(istream& is, Filme& filme);
ostream& operator<<(ostream& os, const CatalogoFilmes& catalogo);

#endif