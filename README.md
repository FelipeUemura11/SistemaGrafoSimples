# Sistema de Grafo Simples em C

Este é um projeto que implementa uma estrutura de dados de grafo não direcionado em C, utilizando listas de adjacência para representação.

## Características

- Implementação de grafo não direcionado usando listas de adjacência
- Suporte para até 100 vértices
- Funções para criar e manipular o grafo
- Gerenciamento automático de memória
- Validação de entrada para evitar erros

## Estrutura do Projeto

O projeto consiste em um único arquivo `main.c` que contém:
- Definição das estruturas de dados (`No` e `Grafo`)
- Funções para manipulação do grafo
- Um exemplo de uso com um grafo de 6 vértices

## Funções Principais

- `criarNo(int v)`: Cria um novo nó para a lista de adjacência
- `criarGrafo(int vertices)`: Inicializa um novo grafo com o número especificado de vértices
- `addAresta(Grafo *g, int origem, int destino)`: Adiciona uma aresta entre dois vértices
- `printGrafo(Grafo *g)`: Exibe a representação do grafo
- `liberarGrafo(Grafo *g)`: Libera a memória alocada pelo grafo

## Como Compilar

```bash
gcc main.c -o grafo
```

## Como Executar

```bash
./grafo
```

## Exemplo de Saída

O programa cria um grafo com 6 vértices e exibe sua estrutura:

```
0 -- 1 -- 3 -- 4 -- 5
|    |
2 -- 3
```

## Requisitos

- Compilador C (gcc recomendado)
- Sistema operacional compatível com C

## Licença

Este projeto está sob a licença MIT. Veja o arquivo LICENSE para mais detalhes.

## Contribuições

Contribuições são bem-vindas! Sinta-se à vontade para abrir issues ou enviar pull requests.
