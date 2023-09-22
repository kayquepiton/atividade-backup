#include <iostream>
#include <vector>
#include <string>
#include <regex>

using namespace std;

struct Roteiro
{
    string codigo;
    string dataHoraPrevista;
    string duracaoPrevista;
    string origem;
    string destino;
};

void criaRoteiro(vector<Roteiro> &roteiros)
{
    Roteiro roteiro;
    regex datahoraValida(R"((0[1-9]|[12][0-9]|3[01])/(0[1-9]|1[0-2])/\d{4} (0[0-9]|1[0-9]|2[0-3]):[0-5][0-9])"),
        duracaoValida("([01]?[0-9]|2[0-3]):[0-5][0-9]");

    cout << "\nInforme o Código do roteiro a ser cadastrado: ";
    cin >> roteiro.codigo;

    for (Roteiro &it : roteiros)
    {
        if (it.codigo == roteiro.codigo)
        {
            cout << "Codigo ja cadastrado!" << endl;
            return;
        }
    }

    cout << "Informe a Data e Hora Prevista (formato dd/mm/aaaa hh:mm): ";
    cin.ignore();
    getline(cin, roteiro.dataHoraPrevista);

    while (true)
    {
        if (regex_match(roteiro.dataHoraPrevista, datahoraValida))
        {
            break;
        }
        else
        {
            cout << "Data ou hora invalida (dd/mm/aaaa hh:mm), tente novamente: ";
            getline(cin, roteiro.dataHoraPrevista);
        }
    }

    cout << "Informe a Duração Prevista (formato hh:mm): ";
    cin >> roteiro.duracaoPrevista;

    while (true)
    {
        if (regex_match(roteiro.duracaoPrevista, duracaoValida))
        {
            break;
        }
        else
        {
            cout << "Duração inválida (hh:mm), tente novamente: ";
            cin >> roteiro.duracaoPrevista;
        }
    }

    cout << "Informe a Origem: ";
    cin.ignore();
    getline(cin, roteiro.origem);

    cout << "Informe o Destino: ";
    getline(cin, roteiro.destino);

    roteiros.push_back(roteiro);

    cout << "Roteiro cadastrado com sucesso!" << endl;
}

void excluirRoteiro(vector<Roteiro> &roteiros)
{
    string codigo;
    cout << "\nInforme o código do roteiro a ser excluído: ";
    cin >> codigo;

    for (auto it = roteiros.begin(); it != roteiros.end(); ++it)
    {
        if (it->codigo == codigo)
        {
            roteiros.erase(it);
            cout << "\nRoteiro excluido com sucesso!" << endl;
            return;
        }
    }

    cout << "\nRoteiro não encontrado." << endl;
}

void alteraRoteiro(vector<Roteiro> &roteiros)
{
    string codigo;
    char decisao;

    cout << "\nDeseja alterar o Código? Se sim, pedimos para que insira os dados do roteiro novamente (s/n): ";
    cin >> decisao;

    if (decisao == 's' || decisao == 'S')
    {
        excluirRoteiro(roteiros);
        criaRoteiro(roteiros);
        return;
    }

    cout << "Informe o codigo do roteiro que terá os dados alterados: ";
    cin >> codigo;

    for (Roteiro &it : roteiros)
    {
        if (it.codigo == codigo)
        {
            cout << "Deseja modificar a data e hora prevista?? (s/n): ";
            cin >> decisao;
            cin.ignore();

            if (decisao == 's' || decisao == 'S')
            {
                cout << "Insira a nova data e hora: ";
                cin >> it.dataHoraPrevista;
            }

            cout << "Deseja modificar a duracao prevista? (s/n): ";
            cin >> decisao;

            if (decisao == 's' || decisao == 'S')
            {
                cout << "Insira a nova duracao prevista: ";
                cin >> it.duracaoPrevista;
            }

            cout << "Deseja modificar a origem? (s/n): ";
            cin >> decisao;
            cin.ignore();

            if (decisao == 's' || decisao == 'S')
            {
                cout << "Insira a nova origem: ";
                getline(cin, it.origem);
            }

            cout << "Deseja modificar o destino? (s/n): ";
            cin >> decisao;
            cin.ignore();

            if (decisao == 's' || decisao == 'S')
            {
                cout << "Insira o novo desino: ";
                getline(cin, it.destino);
            }

            cout << "Roteiro atualizado com sucesso!" << endl;
            return;
        }
    }

    cout << "Roteiro nao encontrado." << endl;
}

void listaRoteiro(vector<Roteiro> &roteiros)
{
    if (roteiros.empty())
    {
        cout << "\nNão existem roteiros cadastrados!" << endl;
        return;
    }
    cout << "\nLista de roteiros cadastrados:" << endl;
    for (Roteiro &it : roteiros)
    {
        cout << "Codigo: " << it.codigo << ", Data Hora prevista: " << it.dataHoraPrevista << ", Duracao prevista: " << it.duracaoPrevista << ", Origem: " << it.origem << ", Destino: " << it.destino << endl;
    }
}

void localizaRoteiro(vector<Roteiro> &roteiros)
{
    if (roteiros.empty())
    {
        cout << "\nA lista de Roteiros está vazia." << endl;
        return;
    }
    string codigo;
    cout << "\nInforme o código do roteiro a ser localizado: ";
    cin >> codigo;

    for (Roteiro &it : roteiros)
    {
        if (it.codigo == codigo)
        {
            cout << "\nRoteiro encontrado!" << endl;
            cout << "Codigo: " << it.codigo << ", Data Hora prevista: " << it.dataHoraPrevista << ", Duracao prevista: " << it.duracaoPrevista << ", Origem: " << it.origem << ", Destino: " << it.destino << endl;
            return;
        }
    }

    cout << "\nRoteiro nao encontrado!" << endl;
}

void menuRoteiro(vector<Roteiro> &roteiros){
    
    while(true){

        cout << endl
        << "==== Gestão de Roteiros ==== " << endl <<"Serviços disponíveis:" << endl;
        cout << "1. Incluir " << endl;
        cout << "2. Excluir" << endl;
        cout << "3. Alterar (apenas por código)" << endl;
        cout << "4. Listar" << endl;
        cout << "5. Localizar (apenas por código)" << endl;
        cout << "0. Voltar ao Menu Principal" << endl;
        cout << "Escolha uma opção: ";

        int opcao;
        cin >> opcao;

        switch (opcao){

            case 1:
                criaRoteiro(roteiros);
                break;
            case 2:
                excluirRoteiro(roteiros);
                break;
            case 3:
                alteraRoteiro(roteiros);
                break;
            case 4:
                listaRoteiro(roteiros);
                break;
            case 5:
                localizaRoteiro(roteiros);
                break;
            case 0:
                cout << "Voltando ao Menu Principal" << endl;
                return;

            default:
                cout << "Informe um valor válido!" << endl;
                break;
        }
    }
    
}