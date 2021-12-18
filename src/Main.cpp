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

    Node node;
    KruscalAlgorithm ka(nodes_number);
    int index = 0;
    std::string *position;
    while (std::getline(input_file, line))
    {
        node.index = index;
        node.is_drone_supporting = false;
        node.nodes_set_index = index;
        position = Utils::split(line, 2);
        node.position[0] = stoi(position[0]);
        node.position[1] = stoi(position[1]);
        delete[] position;
        index++;
        ka.insert_node(node);

    }
    
    input_file.close();

    Edge *result = ka.get_mst();

    return 0;
}