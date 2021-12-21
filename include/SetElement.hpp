#ifndef SET_ELEMENT
#define SET_ELEMENT
#include "Node.hpp"

/* Unidade elementar que compoe a estrutura de dados "Set" */
struct SetElement
{
    SetElement* next;
    Node* node;
};

#endif