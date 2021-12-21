#ifndef EDGE
#define EDGE

#include "Node.hpp"

/* As arestas representam as ligacoes que podem exitir entre duas lojas. */
struct Edge
{
    Node* boundaries[2];
    float distance;
    bool is_a_spanning_tree_edge;
};

#endif
