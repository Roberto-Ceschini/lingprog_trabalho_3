#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "catalogoFilmes.h"

using namespace std;

int main() {
    map<string, CatalogoFilmes> gerenciador;

    gerenciador.insert({"principal", CatalogoFilmes(15, "principal.txt")});
    
    string catalogoAtivo = "principal"; 
    int opcao = 0;

    while (opcao != 8) {
        cout << "\n========================================" << endl;
        cout << "       GERENCIADOR DE CATALOGOS         " << endl;
        cout << "   [ CATALOGO ATIVO: " << catalogoAtivo << " ]" << endl;
        cout << "========================================" << endl;
        cout << "1. Criar / Mudar para outro Catalogo" << endl;
        cout << "2. Adicionar Filme ao Catalogo Ativo (+)" << endl;
        cout << "3. Remover Filme do Catalogo Ativo (-)" << endl;
        cout << "4. Buscar por Diretor no Catalogo Ativo ([])" << endl;
        cout << "5. Atualizar Nota no Catalogo Ativo (())" << endl;
        cout << "6. Comparar tamanho com outro Catalogo (>)" << endl;
        cout << "7. Visualizar Catalogo Ativo Completo (<<)" << endl;
        cout << "8. Sair e Salvar Tudo" << endl;
        cout << "========================================" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;
        cin.ignore();

        if (opcao == 1) {
            string novoNome;
            int novaCapacidade;
            cout << "\nDigite o nome do catalogo que deseja usar/criar: ";
            cin >> novoNome;
            cin.ignore();

            cout << "Digite a capacidade do novo catalogo: ";
            cin >> novaCapacidade;
            cin.ignore();

            if (gerenciador.find(novoNome) == gerenciador.end()) {

                string nomeArquivo = novoNome + ".txt";
                gerenciador.insert({novoNome, CatalogoFilmes(novaCapacidade, nomeArquivo)});
                cout << "Um novo catalogo chamado '" << novoNome << "' foi criado e associado ao arquivo '" << nomeArquivo << "Com capacidade de " << novaCapacidade << " filmes." << endl;
            }

            catalogoAtivo = novoNome;
            cout << "Voce agora esta mexendo no catalogo: " << catalogoAtivo << endl;
        }
        
       else if (opcao == 2) {
        
            Filme novoFilme;
            cout << "\n--- Adicionar Novo Filme ---" << endl;
            
            cout << "Digite o Titulo do filme: ";
            getline(cin, novoFilme.titulo);
            
            cout << "Digite o nome do Diretor: ";
            getline(cin, novoFilme.diretor);
            
            cout << "Digite o Ano de Lancamento: ";
            cin >> novoFilme.anoLancamento;
            
            cout << "Digite a Nota Media (ex: 8.5): ";
            cin >> novoFilme.notaMedia;
            cin.ignore(); 

            gerenciador.at(catalogoAtivo) = gerenciador.at(catalogoAtivo) + novoFilme;
            
            cout << "\nOperacao realizada!" << endl;
        }
        
        else if (opcao == 3) {
            Filme filmeParaRemover;
            cout << "\n--- Remover Filme ---" << endl;
            cout << "Digite o Titulo: ";
            getline(cin, filmeParaRemover.titulo);
            
            gerenciador.at(catalogoAtivo) = gerenciador.at(catalogoAtivo) - filmeParaRemover;
        }
        
        else if (opcao == 4) {
            string diretor;
            cout << "\n--- Buscar por Diretor ---" << endl;
            cout << "Digite o nome do Diretor: ";
            getline(cin, diretor);

            vector<Filme> resultados = gerenciador.at(catalogoAtivo)[diretor];

            if (resultados.empty()) {
                cout << "Nenhum filme encontrado." << endl;
            } else {
                for (const Filme& f : resultados) cout << f;
            }
        }
        
        else if (opcao == 5) {
            string titulo;
            double novaNota;
            cout << "\n--- Atualizar Nota ---" << endl;
            cout << "Titulo: "; getline(cin, titulo);
            cout << "Nota: "; cin >> novaNota; cin.ignore();

            gerenciador.at(catalogoAtivo)(titulo, novaNota);
        }
        
        else if (opcao == 6) {
            string outroCatalogo;
            cout << "\n--- Comparar Catalogos ---" << endl;
            cout << "Digite o nome do outro catalogo para comparar com '" << catalogoAtivo << "': ";
            cin >> outroCatalogo;
            cin.ignore();

            if (gerenciador.find(outroCatalogo) == gerenciador.end()) {
                cout << "Erro: O catalogo '" << outroCatalogo << "' nao existe no sistema." << endl;
            } else {
             
                if (gerenciador.at(catalogoAtivo) > gerenciador.at(outroCatalogo)) {
                    cout << "O catalogo '" << catalogoAtivo << "' tem MAIS filmes que '" << outroCatalogo << "'." << endl;
                } else {
                    cout << "O catalogo '" << catalogoAtivo << "' NAO tem mais filmes que '" << outroCatalogo << "'." << endl;
                }
            }
        }
        
        else if (opcao == 7) {
            cout << "\n=== EXIBINDO CATALOGO: " << catalogoAtivo << " ===" << endl;
           
            cout << gerenciador.at(catalogoAtivo); 
        }
    }

    cout << "\nSaindo... Todos os arquivos de todos os catalogos criados foram salvos!" << endl;
    return 0; 
}