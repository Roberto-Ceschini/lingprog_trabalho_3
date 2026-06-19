#include "catalogoFilmes.h"
#include <iostream>

using namespace std;

int main() {
    // 1. Criar o catálogo (isso já vai ler o arquivo .txt automaticamente)
    CatalogoFilmes meuCatalogo(10); 

    // 2. Criar um filme para teste
    Filme f1 = {"Inception", "Nolan", 2010, 9.5};

    // 3. Testar a sobrecarga do +
    meuCatalogo = meuCatalogo + f1;

    // 4. Testar a sobrecarga do << (imprimir o catálogo todo)
    cout << "Conteudo do Catalogo:" << endl;
    cout << meuCatalogo << endl;

    return 0; // O destrutor ~CatalogoFilmes será chamado aqui e salvará o .txt!
}