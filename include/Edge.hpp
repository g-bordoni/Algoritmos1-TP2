#include "Node.hpp"

struct Edge
{
    Node* boundaries;
    float distance;
    bool is_drone_covered;
    bool is_a_spanning_tree_edge;
};
