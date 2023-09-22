#include <iostream>
#include "passageiro_functions.cpp"
#include "roteiro_functions.cpp"
#include "embarque_functions.cpp"

using namespace std;

int main()
{
    vector<Passageiro> listaPassageiros;
    vector<Roteiro> listaRoteiros;
    vector<Embarque> listaEmbarques;

    while (true)
    {
        cout << endl
             << "==== Menu Principal ==== " << endl
             << "Serviços disponíveis:" << endl;
        cout << "1. Gestão de Passageiros " << endl;
        cout << "2. Gestão de Roteiros" << endl;
        cout << "3. Gestão de Embarques" << endl;
        cout << "4. Gestão de Ocorrências" << endl;
        cout << "0. Sair." << endl;
        cout << "Escolha uma opção: ";

        int opcao;
        cin >> opcao;

        switch (opcao)
        {

        case 1:
            menuPassageiro(listaPassageiros);
            break;
        case 2:
            menuRoteiro(listaRoteiros);
            break;
        case 3:
            menuEmbarque(listaEmbarques, listaPassageiros, listaRoteiros);
            break;
        case 4:
            menuOcorrencia(listaEmbarques);
            break;
        case 0:
            cout << "Programa finalizado!" << endl;
            return;
        default:
            cout << "Informe um valor válido!" << endl;
            break;
        }
    }

    return 0;
}