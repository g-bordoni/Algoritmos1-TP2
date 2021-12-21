#include "SetElement.hpp"


/* Uma implementacao do union-set. Tem como objetivo agregar um conjunto de vertices
    por meio de um set_index a fim de que no fim possamos gerar um caminho sem ciclos */
class Set
{
public:
    int index;
    SetElement* first_element;
    SetElement* last_element;
    int size;

    Set();
    ~Set();

    /* Eh o unico momento em que ocorre a insercao de um vertice no conjunto que nao advem de
        outro Set. Nesse momento que definimos a cheve o Set, pois ela nada mais eh que o 
        index do vertice inserido */
    void first_insertion(Node* node);

    /* Adiciona todos os vertices de um conjunto ao outro. Como otimizacao, a insercao eh feita
        do menor conjunto ao maior */
    void join(Set* set);
};
