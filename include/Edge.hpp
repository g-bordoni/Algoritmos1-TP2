#ifndef EDGE
#define EDGE

#include "Node.hpp"

struct Edge
{
    Node* boundaries[2];
    float distance;
    bool is_drone_covered;
    bool is_a_spanning_tree_edge;
};

#endif
