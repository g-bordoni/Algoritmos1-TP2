#include "../include/Edge.hpp"
#include "../include/MergeSort.hpp"


void MergeSort::merge (Edge* edges_array, int begin, int middle, int end)
{
    int left_array_size = middle - begin + 1;
    int right_array_size = end - middle;
    Edge* left_array = new Edge[left_array_size];
    Edge* right_array = new Edge[right_array_size];

    int i,j,k;
    for (i = 0; i < left_array_size; i++)
        left_array[i] = edges_array[begin + i];
    for (j = 0; j < right_array_size; j++)
        right_array[j] = edges_array[middle + j + 1];

    i = 0; j =0;
    k = begin;
    while (i < left_array_size && j < right_array_size)
    {
        if (left_array[i].distance >= right_array[j].distance)
        {
            edges_array[k] = left_array[i];
            i++;
        } 
        else 
        {
            edges_array[k] = right_array[j];
            j++;
        }
        k++;
    }

    while (i < left_array_size)
    {
        edges_array[k] = left_array[i];
        i++;
        k++;
    }
    while (j < right_array_size)
    {
        edges_array[k] = right_array[j];
        j++;
        k++;
    }

    delete[] left_array;
    delete[] right_array;   
}

void MergeSort::merge_sort(Edge* edges_array, int begin, int end)
{
    if (begin < end)
    {
        int medium = (begin + end) / 2;
        MergeSort::merge_sort(edges_array, begin, medium);
        MergeSort::merge_sort(edges_array, medium + 1, end);
        MergeSort::merge(edges_array, begin, medium, end);
    }
}