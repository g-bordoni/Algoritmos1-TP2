#include "Edge.hpp"

/* Metodo de ordenacao para um array de arestas */
namespace MergeSort
{
    /* A partir de dois arrys eh gerado um unico array por suas unioes, no processo ocorre a
        ordenacao dos elementos agregados */
    void merge(Edge* edges_array, int begin, int middle, int end);
    
    /* A partir de um array original, recursivamente vai dividindo-o pela metade e chamando
        a funcao "merge" */
    void merge_sort(Edge* edges_array, int begin, int end);
};
