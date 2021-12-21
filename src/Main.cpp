#include "../include/MergeSort.hpp"
#include "../include/Utils.hpp"
#include "../include/KruskalAlgorithm.hpp"

#include <string>
#include <iostream>
#include <fstream>
#include <cmath>



int main (int argc, char* argv[])
{
    std::string filename(argv[1]);
    std::fstream input_file(filename);

    if (!input_file.is_open())
        throw "ERROR: File not found.";
    
    std::string line;

    std::getline(input_file, line);
    std::string* input_variables = Utils::split(line, 5);

    int nodes_number = std::stoi(input_variables[0]);
    int drones_available = std::stoi(input_variables[2]);
    int motorcycles_limit = std::stoi(input_variables[1]);
    int motorcycles_price = std::stoi(input_variables[3]);
    int truck_price = std::stoi(input_variables[4]);

    KruskalAlgorithm kruskal(nodes_number);
    std::string *position;
    while (std::getline(input_file, line))
    {
        position = Utils::split(line, 2);
        kruskal.insert(stoi(position[0]), stoi(position[1]));
        delete[] position;        
    }
    
    input_file.close();

    Edge *minimum_spanning_tree = kruskal.get_mst();

    float used_km_per_motorcycles = 0.0;
    float used_km_per_trucks = 0.0;

    for (int i = nodes_number - 1 - drones_available; i >= 0; i--)
    {
        if (minimum_spanning_tree[i].distance > motorcycles_limit)
            used_km_per_trucks += float(minimum_spanning_tree[i].distance);
        else
            used_km_per_motorcycles += float(minimum_spanning_tree[i].distance);
    }

    float cost_motocycles = used_km_per_motorcycles * motorcycles_price;
    float cost_trucks = used_km_per_trucks * truck_price;  
    std::cout << std::fixed <<std::setprecision(3) << cost_motocycles;
    std::cout << " ";
    std::cout << std::fixed <<std::setprecision(3) << cost_trucks;

    return 0;
}