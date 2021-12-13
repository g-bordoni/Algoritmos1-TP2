#include "../include/KruscalAlgorithm.hpp"


KruscalAlgorithm::KruscalAlgorithm(int n)
{
    this->nodes_list = new Node[n];
    this->flattened_adjacency_matrix = new Edge[n * (n-1) / 2];
    this->nodes_sets = new Set[n];
    this->nodes_number = n;
    this->added_nodes = 0;
}

void KruscalAlgorithm::insert_node(Node* node)
{
    this->nodes_list[this->added_nodes] = *node;
    

}

KruscalAlgorithm::~KruscalAlgorithm()
{
}

