#include "../include/MergeSort.hpp"
#include "../include/Utils.hpp"
#include "../include/KruscalAlgorithm.hpp"

#include <string>
#include <iostream>
#include <fstream>


int* test_1(Edge* list, int size)
{
    unsigned found = 0;
    int *edges_index = new int[2];
    int boundary_index[2];
    for (int i=size-1; i>=0; i--)
    {
        if (found >= 2) break;
        else 
        {
            if (list[i].boundaries[0]->is_drone_supporting || list[i].boundaries[1]->is_drone_supporting)
            {
                if(!list[i].boundaries[0]->is_drone_supporting)
                {
                    list[i].boundaries[0]->is_drone_supporting = true;
                    edges_index[found] = i;
                    boundary_index[found] = 0;
                    found++;
                }
                else if (!list[i].boundaries[1]->is_drone_supporting)
                {
                    list[i].boundaries[1]->is_drone_supporting = true;
                    edges_index[found] = i;
                    boundary_index[found] = 1;
                    found++;
                }
                else continue;
            }
        }
    }
    for (int i = 0; i<2; i++)
    {
        if (i<found)
            list[edges_index[i]].boundaries[boundary_index[i]]->is_drone_supporting = false;
        else
            edges_index[i] = -1;
    }
    return edges_index;
}

int test_2(Edge* list, int size)
{
    for(int i=size-1; i>=0; i--)
    {
        if(!list[i].boundaries[0]->is_drone_supporting && !list[i].boundaries[1]->is_drone_supporting)
        {
            return i;
        }
    }
    return -1;
}


int main (int argc, char* argv[])
{
    std::string filename(argv[1]);
    std::fstream input_file(filename);

    if (!input_file.is_open())
        throw "ERROR: Openning file has failed.";
    
    std::string line;

    std::getline(input_file, line);
    std::string* input_variables = Utils::split(line, 5);

    int nodes_number = std::stoi(input_variables[0]);
    int drones_available = std::stoi(input_variables[2]);
    int motocycles_limit = std::stoi(input_variables[1]);
    int motocycles_price = std::stoi(input_variables[3]);
    int truck_price = std::stoi(input_variables[4]);

    KruscalAlgorithm ka(nodes_number);
    std::string *position;
    while (std::getline(input_file, line))
    {
        position = Utils::split(line, 2);
        ka.insert(stoi(position[0]), stoi(position[1]));
        delete[] position;        
    }
    
    input_file.close();

    Edge *result = ka.get_mst();

    float used_km_per_motocycles = 0.0;
    float used_km_per_trucks = 0.0;

    int* aux;
    int aux1;
    int size = nodes_number -1;
    int action = 0;
    while (drones_available)
    {
        if (drones_available == 1)
        {
            aux = test_1(result, size);
            if (aux[0] < 0) break;
            result[aux[0]].is_drone_covered = true;
            drones_available--;
        }
        else
        {
            aux = test_1(result, size);
            aux1 = test_2(result, size);
            if (aux[0] < 0 || aux[1] < 0) action = 2;
            if (action == 0 && aux1 < 0) action = 1;
            if (action == 0) 
                action = ((result[aux[0]].distance + result[aux[1]].distance) > result[aux1].distance)? 1:2;
            if (action==1)
            {
                result[aux[0]].boundaries[0]->is_drone_supporting = true;
                result[aux[0]].boundaries[1]->is_drone_supporting = true;
                result[aux[1]].boundaries[0]->is_drone_supporting = true;
                result[aux[1]].boundaries[1]->is_drone_supporting = true;
                result[aux[0]].is_drone_covered = true;
                result[aux[1]].is_drone_covered = true;
                drones_available -= 2;
            }
            else
            {
                result[aux1].boundaries[0]->is_drone_supporting = true;
                result[aux1].boundaries[1]->is_drone_supporting = true;
                result[aux1].is_drone_covered = true;
                drones_available -= 2;
            }
            delete[] aux;
        }
    }

    for (int i = nodes_number - 2; i >=0; i--)
    {
        if (result[i].is_drone_covered)
            continue;
        else
        {
            if (result[i].distance > motocycles_limit)
                used_km_per_trucks += float(result[i].distance);
            else
                used_km_per_motocycles += float(result[i].distance);
        }
    }

    std::cout << used_km_per_motocycles*motocycles_price;
    std::cout << " ";
    std::cout << used_km_per_trucks*truck_price;

    return 0;
}