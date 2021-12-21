#include "../include/Set.hpp"


Set::Set()
{
    this->first_element = nullptr;
    this->last_element = nullptr;
    this->index = -1;
    this->size = 0;
}

void Set::first_insertion(Node* node)
{
    SetElement* new_element = new SetElement;
    new_element->next = nullptr;
    new_element->node = node;

    this->index = node->index;
    this->first_element = new_element;
    this->last_element = new_element;
    this->size = 1;
}

void Set::join(Set* set)
{
    Set *receving_set, *other_set; 
    if (this->size >= set->size)
    {
        receving_set = this;
        other_set = set;
    }
    else
    {
        receving_set = set;
        other_set = this;
    }

    SetElement *element;
    for (int i = 0; i < other_set->size; i++)
    {
        element = other_set->first_element;
        element->node->nodes_set_index = receving_set->index;
        other_set->first_element = other_set->first_element->next;
        receving_set->last_element->next = element;
        receving_set->last_element = element;
    }
    receving_set->size = receving_set->size + other_set->size;
    other_set->size = 0;
}

Set::~Set()
{
    SetElement *element;
    for (int i = 0; i < this->size; i++)
    {
        element = this->first_element;
        this->first_element = this->first_element->next;
        delete element;
    }
}
