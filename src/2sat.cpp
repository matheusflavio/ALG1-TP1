#include <iostream>
#include "2sat.h"

/* Função booleana responsável por retornar se o problema do 2SAT é satisfazível ou não. */
bool get2SATViability(Graph *graph){
	int size = graph->getSize();
	/* Caso o vértice ainda não  tenah sido visitado, roda a primeira DFS para criar
	o de ordem. Como o vetor de visitados é inicializado como sendo todo false, a negação
	desse valor é usado como condição para o if. */
	for(int i = 0; i < size; i++)
		if(!graph->getAlreadyVisited()[i]) graph->dfs(i);
	
	/* Criação das relações de fortemente conectados. Como o 0 é usado como uma flag, caso
	aquele vértice tenha como componente conectado o valor "0", então é realizada a segunda
	DFS para ele. */
	for(int i = 0; i < size; i++) {
		int aux = i+1;
		int vertice = graph->getFirstDFSOrder()[size - i - 1];
		if(graph->getComponentRelation()[vertice] == 0) graph->dfs(vertice, aux);
	}

	/* Análise dos componentes fortemente conectados. Caso o vértice atual seja do mesmo componente
	conectado de seu sucessor, então o 2SAT não é satisfazível e retorna falso. */
	for(int i = 0; i < size; i+=2) {
		if(graph->getComponentRelation()[i] == graph->getComponentRelation()[i+1])
			return false;
	}
	return true;
}