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
    

    while (true)
    {
        menuPassageiro(listaPassageiros);

    }

    return 0;
}