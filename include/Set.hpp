#include "Node.hpp"

struct SetElement
{
    SetElement* next;
    Node* node;

};


class Set
{
public:
    int index;
    SetElement* first_element;
    SetElement* last_element;
    int size;

    Set();
    void first_insertion(Node* node);
    void join(Set* set);
    ~Set();
};
