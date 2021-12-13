#include "../include/Edge.hpp"
#include "../include/Node.hpp"
#include "../include/MergeSort.hpp"
#include "../include/Utils.hpp"

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
    int edges_number = nodes_number * (nodes_number - 1) / 2;
    int drones_available = std::stoi(input_variables[2]);
    int motocycles_limit = std::stoi(input_variables[1]);
    int motocycles_price = std::stoi(input_variables[3]);
    int truck_price = std::stoi(input_variables[4]);

    Node* nodes_list = new Node[nodes_number];
    Edge* flattened_adjacency_matrix = new Edge[edges_number];

    input_file.close();

    return 0;
}