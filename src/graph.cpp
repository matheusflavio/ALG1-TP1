#include "graph.h"
#include <iostream>

/* Função que incializa e atribui todas a s propriedades do grafo. */
Graph::Graph(int size) {
    this->size = 2*size;
    adjacency = new list<int>[this->size + 2]; // Inicialização das listas de adjacência sem valores definidos. É criado como 2*size + 2 por que os valores de índice 0 são dispensados
    adjacencyReverse = new list<int>[this->size + 2]; // Inicialização das listas de adjacência reversa sem valores definidos. É criado como 2*size + 2 por que os valores de índice 0 são dispensados
    alreadyVisited = vector<bool>(this->size, false); // Inicilização do vetor de vértices que já foram conectados. Inicializado como falso porque nenhum vértice ainda foi visitado.
    componentRelation = vector<int>(this->size, 0); // Inicialização do vetor de componentes conectados. 0 é uma flag para indicar que aquele vértice ainda não foi processado. 
}

void Graph::clear() {
    alreadyVisited.clear();
    componentRelation.clear();
}

/* Função responsável por retornar o tamanho do grafo. */
int Graph::getSize() {
    return size;
}

/* Função responsável por retornar o vetor de vértices já visitados. */
vector<bool> Graph::getAlreadyVisited() {
    return alreadyVisited;
}

/* Função responsável por retornar o vetor de componentes conectados. */
vector<int> Graph::getComponentRelation() {
    return componentRelation;
}

/* Função responsável por retornar o vetor de ordem de término da primeira DFS. */
vector<int> Graph::getFirstDFSOrder() {
    return firstDFSOrder;
}

/* Função responsável por adicionar arestas aos vértices de acordo com a definição do 2SAT.
Adiciona simultaneamente tanto ao grafo com as direções originais quanto ao grafo com as direções
reversas. */
void Graph::addEgde(int vertice1, bool negation1, int vertice2, bool negation2) {
    int negVertice1;
    int negVertice2;

    vertice1 = 2 * vertice1;
    vertice2 = 2 * vertice2;

    if (negation1) {
        negVertice1 = vertice1;
        vertice1 += 1;
    }
    else
        negVertice1 = vertice1 + 1;
    
    if (negation2) {
        negVertice2 = vertice2;
        vertice2 += 1;
    }
    else
        negVertice2 = vertice2 + 1;

    adjacency[negVertice1].push_back(vertice2);
    adjacency[negVertice2].push_back(vertice1);
    adjacencyReverse[vertice2].push_back(negVertice1);
    adjacencyReverse[vertice1].push_back(negVertice2);
}

/* Primeira DFS que é rodada. O intuito dela é percorer todos os vértices e preencher a ordem
de término em firstDFSOrder. */
void Graph::dfs(int vertice) {
    alreadyVisited[vertice] = true;
    for(auto i : adjacency[vertice]) {
        if(!alreadyVisited[i]) dfs(i);
    }
    firstDFSOrder.push_back(vertice);
}

/* Função responsável por instanciar os componentes fortemente conectados de cada vértice. */
void Graph::dfs(int vertice, int component){
    componentRelation[vertice] = component;
    for(auto i : adjacencyReverse[vertice]) {
        if(componentRelation[i] == 0) dfs(i, component);
    }
}