#include "Edge.hpp"
#include "Node.hpp"
#include "Set.hpp"
#include "MergeSort.hpp"

class KruscalAlgorithm
{
private:
    int added_nodes;
    Node* nodes_list;
    Edge* flattened_adjacency_matrix;
    Set* nodes_sets;
public:
    KruscalAlgorithm(int n);
    void insert_node(Node node);
    Edge create_edge(Node* node0, Node* node1);
    Edge* get_mst();
    ~KruscalAlgorithm();
};

