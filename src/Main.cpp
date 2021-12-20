#include "../include/MergeSort.hpp"
#include "../include/Utils.hpp"
#include "../include/KruscalAlgorithm.hpp"

#include <string>
#include <iostream>
#include <fstream>



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

    for (int i = nodes_number - 1 - drones_available; i >=0; i--)
    {
        if (result[i].distance > motocycles_limit)
            used_km_per_trucks += float(result[i].distance);
        else
            used_km_per_motocycles += float(result[i].distance);
    }

    std::cout << used_km_per_motocycles*motocycles_price;
    std::cout << " ";
    std::cout << used_km_per_trucks*truck_price;

    return 0;
}