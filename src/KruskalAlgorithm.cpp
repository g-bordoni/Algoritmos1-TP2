#include "../include/KruskalAlgorithm.hpp"
#include <iostream>
#include <math.h>


KruskalAlgorithm::KruskalAlgorithm(int n)
{
    this->nodes_list = new Node[n];
    this->flattened_adjacency_matrix = new Edge[(n * (n-1) / 2)];
    this->nodes_sets = new Set[n];
    this->added_nodes = 0;
}

void KruskalAlgorithm::insert(int lat, int lng)
{
    // Node
    this->nodes_list[this->added_nodes].index = this->added_nodes;
    this->nodes_list[this->added_nodes].position[0] = lat;
    this->nodes_list[this->added_nodes].position[1] = lng;
    this->nodes_list[this->added_nodes].nodes_set_index = this->added_nodes;

    // Set
    this->nodes_sets[this->added_nodes].first_insertion(&this->nodes_list[this->added_nodes]);
    
    // Edge
    Edge new_edge;
    int matrix_correction = this->added_nodes * (this->added_nodes - 1) / 2;
    for (int i = 0; i < this->added_nodes; i++)
    {
        new_edge = this->create_edge(&this->nodes_list[this->added_nodes], &this->nodes_list[i]);
        this->flattened_adjacency_matrix[matrix_correction + i] = new_edge;
    }
    this->added_nodes += 1;
}

Edge KruskalAlgorithm::create_edge(Node* node0, Node* node1)
{
    Edge new_edge;

    float dx = node0->position[0] - node1->position[0];
    float dy = node0->position[1] - node1->position[1];
    new_edge.distance = sqrt(pow(dx, 2) + pow(dy, 2));

    new_edge.boundaries[0] = node0;
    new_edge.boundaries[1] = node1;

    new_edge.is_a_spanning_tree_edge = false;

    return new_edge;
}

Edge* KruskalAlgorithm::get_mst()
{
    MergeSort::merge_sort(this->flattened_adjacency_matrix, 0, this->added_nodes*(this->added_nodes-1)/2 - 1);

    Edge* mst = new Edge[this->added_nodes - 1];
    Node *node0, *node1;
    int i = 0, j = 0;
    while (i < this->added_nodes - 1)
    {
        while (j < this->added_nodes*(this->added_nodes - 1)/2)
        {   
            node0 = this->flattened_adjacency_matrix[j].boundaries[0];
            node1 = this->flattened_adjacency_matrix[j].boundaries[1];
            if(node0->nodes_set_index != node1->nodes_set_index)
            {
                this->nodes_sets[node0->nodes_set_index].join(&this->nodes_sets[node1->nodes_set_index]);
                mst[i] = this->flattened_adjacency_matrix[j];
                i++; j++;
                break;
            }
            j++;
        }
    }
    return mst;
}

KruskalAlgorithm::~KruskalAlgorithm()
{
    delete[] this->nodes_list;
    delete[] this->flattened_adjacency_matrix;
    delete[] this->nodes_sets;
}

