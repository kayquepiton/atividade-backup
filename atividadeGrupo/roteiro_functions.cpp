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

    cout << "Codigo: ";
    cin >> roteiro.codigo;

    for (Roteiro &it : roteiros)
    {
        if (it.codigo == roteiro.codigo)
        {
            cout << "Codigo ja cadastrado!" << endl;
            return;
        }
    }

    cout << "Data hora prevista (dia/mes/ano hh:mm): ";
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
            cout << "Data hora invalida (dia/mes/ano hh:mm), digite novamente: ";
            getline(cin, roteiro.dataHoraPrevista);
        }
    }

    cout << "Duracao prevista (hh:mm): ";
    cin >> roteiro.duracaoPrevista;

    while (true)
    {
        if (regex_match(roteiro.duracaoPrevista, duracaoValida))
        {
            break;
        }
        else
        {
            cout << "Duracao invalida (hh:mm), digite novamente: ";
            cin >> roteiro.duracaoPrevista;
        }
    }

    cout << "Origem: ";
    cin.ignore();
    getline(cin, roteiro.origem);

    cout << "Destino: ";
    getline(cin, roteiro.destino);

    roteiros.push_back(roteiro);

    cout << "Roteiro inserido!" << endl;
}

void excluirRoteiro(vector<Roteiro> &roteiros)
{
    string codigo;
    cout << "Digite o Codigo do roteiro para excluir: ";
    cin >> codigo;

    for (auto it = roteiros.begin(); it != roteiros.end(); ++it)
    {
        if (it->codigo == codigo)
        {
            roteiros.erase(it);
            cout << "Roteiro excluido com sucesso!" << endl;
            return;
        }
    }

    cout << "Roteiro nao encontrado." << endl;
}

void alteraRoteiro(vector<Roteiro> &roteiros)
{
    string codigo;
    char decisao;

    cout << "Deseja alterar o codigo? (s/n): ";
    cin >> decisao;

    if (decisao == 's')
    {
        excluirRoteiro(roteiros);
        criaRoteiro(roteiros);
        return;
    }

    cout << "Digite o codigo do roteiro que tera os dados alterados: ";
    cin >> codigo;

    for (Roteiro &it : roteiros)
    {
        if (it.codigo == codigo)
        {
            cout << "Deseja mudar a data hora prevista?? (s/n): ";
            cin >> decisao;
            cin.ignore();

            if (decisao == 's')
            {
                cout << "Nova data hora: ";
                cin >> it.dataHoraPrevista;
            }

            cout << "Deseja mudar a duracao prevista? (s/n): ";
            cin >> decisao;

            if (decisao == 's')
            {
                cout << "Nova duracao prevista: ";
                cin >> it.duracaoPrevista;
            }

            cout << "Deseja mudar a origem? (s/n): ";
            cin >> decisao;
            cin.ignore();

            if (decisao == 's')
            {
                cout << "Nova origem: ";
                getline(cin, it.origem);
            }

            cout << "Deseja mudar o destino? (s/n): ";
            cin >> decisao;
            cin.ignore();

            if (decisao == 's')
            {
                cout << "Novo desino: ";
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
        cout << "Nao existem roteiros!" << endl;
        return;
    }
    cout << "Roteiros:" << endl;
    for (Roteiro &it : roteiros)
    {
        cout << "Codigo: " << it.codigo << ", Data Hora prevista: " << it.dataHoraPrevista << ", Duracao prevista: " << it.duracaoPrevista << ", Origem: " << it.origem << ", Destino: " << it.destino << endl;
    }
}

void localizaRoteiro(vector<Roteiro> &roteiros)
{
    string codigo;
    cout << "Digite o codigo do roteiro para localizar: ";
    cin >> codigo;

    if (roteiros.empty())
    {
        cout << "A lista de Roteiros está vazia." << endl;
        return;
    }
    cout << "Lista de roteiros:" << endl;
    for (Roteiro &it : roteiros)
    {
        if (it.codigo == codigo)
        {
            cout << "Roteiro encontrado!" << endl;
            cout << "Codigo: " << it.codigo << ", Data Hora prevista: " << it.dataHoraPrevista << ", Duracao prevista: " << it.duracaoPrevista << ", Origem: " << it.origem << ", Destino: " << it.destino << endl;
            return;
        }
    }

    cout << "Roteiro nao encontrado!" << endl;
}
