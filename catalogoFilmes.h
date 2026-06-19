

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

    public:
        CatalogoFilmes(int);
        ~CatalogoFilmes(); //coloquei para lembrar de usar o destrutor para salvar o catalogo ao fechar o programa
        
        CatalogoFilmes operator + (const Filme&);

    private:

        vector<Filme> catalogo;
        int capacidade;

        string nomeArquivo = "catalogo.txt";

        void carregarArquivo();
        void salvarArquivo();
};

//perguntar por que isso da certo??
ostream& operator<<(ostream& os, const Filme& filme);
istream& operator>>(istream& is, Filme& filme);
ostream& operator<<(ostream& os, const CatalogoFilmes& catalogo);

#endif