#include "Edge.hpp"
#include "Node.hpp"
#include "Set.hpp"
#include "MergeSort.hpp"

/* A partir das posicoes fornecidas, geram os vertices e as arestas que formam
    o grafo do problema com o objetivo de ao final gerar uma arvore geradora minima do mesmo.
 */
class KruskalAlgorithm
{
private:
    int added_nodes;
    Node* nodes_list;
    Edge* flattened_adjacency_matrix;
    Set* nodes_sets;

    /* Cria o vertice requisitado pela funcao "insert" */
    Edge create_edge(Node* node0, Node* node1);
    
public:
    KruskalAlgorithm(int n);
    ~KruskalAlgorithm();

    /* A partir das posicoes cria um vertice e o adiciona na lista de vertices. Do vertice novo,
        é criado entao uma nova aresta para cada uma das ligacoes que ele podem ter com os 
        vertices ja existentes e as adicionam na matrix de adjacencia unidimensional. Alem
        dessas instanciacoes, tambem eh reponsavel por instanciar o Set que o vertice pertence.
    */
    void insert(int lat, int lng);

    /* Retorna a arvore geradora minima do problema. Primeiro ordena a lista que representa a
        matriz de adjacencia e entao usa a estrutura de dados union-set para separar dela
        as arestas que formam a mst.
    */
    Edge* get_mst();
};

