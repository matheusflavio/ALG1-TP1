#include <vector>
#include <list>

using namespace std;

class Graph {
    private:
        /* Inteiro que gera o grafo e cujo valor é 2 vezes o número de propostas. Essencial
        para gerenciar as listas de adjacência, iterações e propriedades gerais do grafo. */
        int size;

        /* Listas de ajacências no sentido direto e reverso sobre as propostas e suas
        relações de acordo com o 2SAT. */
        list<int>* adjacency;
        list<int>* adjacencyReverse;

        /* Vetor que armazena a ordem de término da priemira DSF para o 2SAT. Como a ordem é
        adicionada com o método push_back(), sempre os primeiros a terminar têm os menores
        índices, correspondendo justamente à ordem. */
        vector<int> firstDFSOrder;

        /* Vetor que armazena a relação de componentes fortemente conectados para cada vértice. */
        vector<int> componentRelation;

        /* Vetor booleano que inidica se determinado vértice já foi visitado. Utilizado para a
        primeira DFS do 2SAT. */
        vector<bool> alreadyVisited;

    public:
        Graph(int size);
        int getSize();

        /* Função que retorna o vetor de vértices que já foram visitados. */
        vector<bool> getAlreadyVisited();

        /* Função que retorna o vetor de ordem de finalização da primeira DFS necessária
        para realização do 2SAT. */
        vector<int> getFirstDFSOrder();

        /* Função que retorna o vetor de relação dos componentes fortmente conectados. */
        vector<int> getComponentRelation();

        /* Função que adiciona uma aresta no grafo de acordo com a premissa do 2SAT. */
        void addEgde(int vertice1, bool negation1, int vertice2, bool negation2);

        /* Função que funciona como a primeira DFS para resolução do 2SAT, sendo importante
        para definir a ordem de término para a variável firstDFSOder. */
        void dfs(int vertice);
        
        /* Função que funciona como a segunda DFS para resolução do 2SAT, montando a relação
        entre vértices e componentes conectados para análise. */
        void dfs(int vertice1, int vertice2);

        void clear();
};