#include <string>

/* Funcoes para auxiliar a manipulacao de dados */
namespace Utils
{
    /* Separa os caracteres de uma string, tendo como referencia o caracter de espaco,
        e os retorna em um vetor. O argumento "return_expected_size" nada mais eh que
        o tamanho do vetor de retorno. */
    std::string* split(std::string original, int return_expected_size);
};
