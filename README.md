# Gerenciador de Catálogo de Filmes em C++

## Descrição

Sistema desenvolvido em C++ para o gerenciamento de múltiplos catálogos de filmes em tempo de execução, utilizando persistência de dados em arquivos `.txt` e ampla sobrecarga de operadores.

O sistema permite a manipulação dinâmica de acervos, mantendo os filmes inseridos sempre ordenados de forma automática.

O sistema permite:
- Criação e alternância entre múltiplos catálogos em tempo de execução.
- Persistência automática dos dados em arquivos específicos por catálogo.
- Ordenação automática dos filmes por Diretor e, em caso de empate, por Título.
- Busca filtrada de produções e atualização de notas em memória.

---

# Estrutura do Projeto

## Estruturas e Classes

### Filme (Struct)
Responsável por representar uma produção cinematográfica individual.
Cada filme possui:
- Título
- Diretor
- Ano de Lançamento
- Nota Média

---

### CatalogoFilmes (Classe)
Classe principal responsável pelo armazenamento, encapsulamento e gerenciamento dos filmes.
A estrutura interna utiliza:
- Vetor dinâmico (`std::vector<Filme>`) para armazenamento.
- Capacidade máxima definida via construtor.
- Nome do arquivo associado para persistência.

---

# Formato do Arquivo de Entrada/Saída

Os dados armazenados nos arquivos `.txt` seguem o formato padronizado com rótulos textuais:

```txt
Titulo: Inception
Diretor: Christopher Nolan
Ano: 2010
Nota: 9.5
-----------------------------
Titulo: Interstellar
Diretor: Christopher Nolan
Ano: 2014
Nota: 9.2
-----------------------------
Funcionalidades e Operadores
Todas as operações do sistema foram mapeadas e executadas por intermédio da sobrecarga de operadores:

Adicionar Filme (operator+): Insere um filme validando a capacidade máxima e duplicidade de títulos, ordenando o catálogo automaticamente (std::sort integrado ao operator<).

Remover Filme (operator-): Remove um filme do catálogo com base na igualdade de títulos (operator==).

Buscar por Diretor (operator[]): Retorna um vetor contendo todos os filmes do diretor informado.

Atualizar Nota (operator()): Localiza o filme pelo título e atualiza sua nota média diretamente no catálogo ativo, retornando sucesso (true) ou falha (false).

Comparar Catálogos (operator>): Compara se o catálogo atual possui mais filmes cadastrados que o outro.

Impressão do Catálogo/Filme (operator<<): Envia os dados formatados diretamente para o fluxo de saída (cout).

Leitura de Dados (operator>>): Realiza o parsing e extração dos dados tratando marcadores textuais do fluxo de entrada (cin/ifstream).

Requisitos
Para compilar o programa é necessário possuir:

g++ (Suporte a C++11 ou superior)

mingw32-make

Compilação
No terminal, execute:

Bash
mingw32-make
O comando irá gerar o executável do programa.

Execução
Após a compilação:

Bash
.\programa
Limpeza dos Arquivos Compilados
Para remover os arquivos objeto e o executável:

Bash
mingw32-make clean
Observações
Caso utilize Linux, pode ser necessário ajustar os comandos do Makefile. Como mostrado na linha 1 deste arquivo.

Autor
Roberto Ceschin
