#include "Edge.hpp"
#include "Node.hpp"
#include "Set.hpp"
#include "MergeSort.hpp"

class KruscalAlgorithm
{
private:
    int nodes_number;
    int added_nodes;
    Node* nodes_list;
    Edge* flattened_adjacency_matrix;
    Set* nodes_sets;
public:
    KruscalAlgorithm(int n);
    void insert_node(Node* node);
    Edge* create_edge(Node* node0, Node* node1);
    void create_set(Node* node);
    Node* get_mst();
    ~KruscalAlgorithm();
};

