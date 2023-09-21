#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <ctime>
#include <sstream>
#include "passageiro_functions.cpp" 
#include "roteiro_functions.cpp"

using namespace std;

int main()
{
    vector<Passageiro> listaPassageiros;
    vector<Roteiro> listaRoteiros;
    

    while (true)
    {
        menuPassageiro(listaPassageiros);

        menuRoteiro(listaRoteiros);

    }

    return 0;
}