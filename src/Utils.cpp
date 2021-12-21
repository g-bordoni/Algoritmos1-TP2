#include "../include/Utils.hpp"

std::string* Utils::split(std::string original, int return_expected_size)
{
    std::string space = " ";
    int original_size = original.size();
    int current_index = 0;

    std::string* splited_result = new std::string[return_expected_size];
    std::string character;
    std::string splited_word = "";
    for (int i = 0; i < original_size; i++)
    {
        character = original[i];
        if (space.compare(character) == 0)
        {
            splited_result[current_index] = splited_word;
            splited_word = "";
            current_index++;
            continue;
        }
        splited_word.append(character);
        
    }
    splited_result[current_index] = splited_word;
    return splited_result;
}