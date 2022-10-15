#include <iostream>
#include <vector>
#include "2sat.h"

using namespace std;

int main() {
    /* Variáveis para quantidade de seguidores e propostas */
    int followers, proposals;

    /* Variáveis que armazenam as duas propostas que o seguidor aprova (x1, x2) e as
    duas que ele rejeita (y1, y2) */
    int x1, x2, y1, y2;

    /* Leitura inicial para as quantidades de seguidores e propostas */
    cin >> followers >> proposals;


    /* Loop para seguir lendo a entrada até o caso em que a quantidade de proposta e 
    de seguidores são iguais a 0. Essa é a condição de parada. */
    while(followers != 0 && proposals != 0) {
        /* Criação de um grafo em função da quantidade de propostas lidas anteriormente. 
        Observação: O tamanho do grafo é tipo como 2*proposals. É, então, um grafo de 
        tamanho O(proposals)*/
        Graph *graph = new Graph(proposals);

        /* Loop que iterage sobre cada linha a ser lida com as propostas aprovadas e rejeitadas.
        Cada linha diz repeito à cada seguidor */
        for(int i = 0; i < followers; i++) {

            /* Atribuição das variávies x's para os votos de aprovação e y's para os votos de rejeição. */
            cin >> x1 >> x2 >> y1 >> y2;

            /* Desconsiderando o voto do eleitor caso tenha votado dois 0 para a mesma categoria*/
            if(x1 == x2 && x1 == 0) continue;
            if(y1 == y2 && y1 == 0) continue;

            /* Tratramento especial para o caso em que algum dos votos de rejeição ou aprovação
            sejam iguais a 0. Isso significa que o seguidor abriu mão daquele voto, e, por isso,
            seu outro voto daquela categoria tem que OBRIGATIORIAMENTE ser atendido. Foi um dos
            pontos que inicialmente eu não havia entendido*/
            if(x1 == 0) x1 = x2;
            if(x2 == 0) x2 = x1;
            if(y1 == 0) y1 = y2;
            if(y2 == 0) y2 = y1;

            /* Adição de arestas segundo a premissa do booleana do 2SAT em que uma premissa
            verdadeira é conectada a uma premissa falsa que compõe a expressão*/
            graph->addEgde(x1, false, x2, false);
            graph->addEgde(y1, true, y2, true);
        }

        /* Impressão do resultado da pesquisa. Imprime "sim" caso a pesquisa realizada seja
        satisfazível e "nao" caso contrário. O argumento utilizado é a resposta booleana
        dessa satisfabilidade. */
        get2SATViability(graph) ? cout << "sim" : cout << "nao";
        cout << endl;

        /* Atualização das quantidades de seguidores e propostas para o
        próximo caso. Caso sejam ambos 0, a execução do while é interrompida. */
        cin >> followers >> proposals;
        graph = new Graph(proposals); // Reinicialização de graph para evitar erros caso o novo grafo seja menor que o anterior
    }
    return 0;
}