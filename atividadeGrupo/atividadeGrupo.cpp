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
        cout << endl
        << "==== Menu Principal ==== " << endl <<"Serviços disponíveis:" << endl;
        cout << "1. Gestão de Passageiros " << endl;
        cout << "2. Gestão de Roteiros" << endl;
        cout << "3. Gestão de Embarques" << endl;
        cout << "0. Sair." << endl;
        cout << "Escolha uma opção: ";

        int opcao;
        cin >> opcao;

        switch (opcao){

        case 1:
            menuPassageiro(listaPassageiros);
            break;
        case 2:
            menuRoteiro(listaRoteiros);
            break;
        //case 3:
            //menuEnbarque();
        case 0:
            cout << "Programa finalizado!" << endl;
            return;
        default:
            cout << "Digite um valor válido!" << endl;
            break;
        }
       

        

    }

    return 0;
}