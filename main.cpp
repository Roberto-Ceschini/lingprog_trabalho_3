#include "catalogoFilmes.h"
#include <iostream>

using namespace std;

int main() {
    // 1. Criar o catálogo (isso já vai ler o arquivo .txt automaticamente)
    CatalogoFilmes meuCatalogo(10); 

    // 2. Criar um filme para teste
    Filme f1 = {"Inception", "Nolan", 2010, 9.5};
    Filme f2 = {"The Dark Knight", "Nolan", 2008, 9.0};
    Filme f3 = {"Interstellar", "Nolan", 2014, 8.6};
    Filme f4 = {"The Prestige", "Nolan", 2006, 8.5};
    Filme f5 = {"Golan", "Nolan", 2010, 9.5}; // Filme duplicado para teste

    // 3. Testar a sobrecarga do +
    meuCatalogo = meuCatalogo + f1;
    meuCatalogo = meuCatalogo + f2;
    meuCatalogo = meuCatalogo + f3;
    meuCatalogo = meuCatalogo + f4;

    // 4. Testar a sobrecarga do << (imprimir o catálogo todo)
    cout << "Conteudo do Catalogo:" << endl;
    cout << meuCatalogo << endl;

    meuCatalogo = meuCatalogo - f2; // Testando a sobrecarga do operador -
    cout << "Conteudo do Catalogo apos remocao:" << endl;
    cout << meuCatalogo << endl;
    cout << f5 << endl; // Testando a sobrecarga do operador << para Filme



    return 0; // destrutor salva o cataloaogo ao fechar o progrma
}