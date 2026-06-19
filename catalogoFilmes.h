

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
    friend bool operator<(const Filme&, const Filme&);

    public:
        CatalogoFilmes(int, string);
        ~CatalogoFilmes(); //coloquei para lembrar de usar o destrutor para salvar o catalogo ao fechar o programa
        
        CatalogoFilmes operator + (const Filme&);
        CatalogoFilmes operator - (const Filme&);
        bool operator () (const string&, double);
        bool operator > (const CatalogoFilmes&);
        vector <Filme> operator [] (const string& diretor);

    private:

        vector<Filme> catalogo;
        int capacidade;
        string nomeArquivo;

        void carregarArquivo();
        void salvarArquivo();
};

bool operator == (const Filme&, const Filme&);
bool operator < (const Filme&, const Filme&);

//perguntar pq isso da certo?? tipo, essa funcao ja nao ta na ostream? pq eu tenho que declarar ela aqui de novo?
ostream& operator<<(ostream& os, const Filme& filme);
istream& operator>>(istream& is, Filme& filme);
ostream& operator<<(ostream& os, const CatalogoFilmes& catalogo);

#endif