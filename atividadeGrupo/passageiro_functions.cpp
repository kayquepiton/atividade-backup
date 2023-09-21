#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <ctime>
#include <sstream>

using namespace std;

struct Passageiro
{
    string cpf;
    string nome;
    string dataNascimento;
    string numAutorizacao;
};

int calcularIdade(string &dataNascimento) {

    vector<int> componentesData;
    istringstream ss(dataNascimento);
    string componente;
    while (getline(ss, componente, '/')) {
        componentesData.push_back(stoi(componente));
    }

    if (componentesData.size() != 3) {
        cerr << "Formato de data inválido!" << endl;
        return -1;
    }

    int dia = componentesData[0];
    int mes = componentesData[1];
    int ano = componentesData[2];

    time_t agora = time(nullptr);
    tm tmAtual = *localtime(&agora);

    int idade = tmAtual.tm_year + 1900 - ano;

    if (mes > tmAtual.tm_mon + 1 || (mes == tmAtual.tm_mon + 1 && dia > tmAtual.tm_mday)) {
        idade--;
    }

    return idade;
}

void criaPassageiro(vector<Passageiro> &passageiros)
{
    Passageiro passageiro;
    regex cpfValido(R"(\d{3}\.\d{3}\.\d{3}-\d{2})"),
        dataValida("^(0[1-9]|[12][0-9]|3[01])/(0[1-9]|1[0-2])/\\d{4}$");

    cout << "\nInforme o CPF do passageiro a ser incluído (xxx.xxx.xxx-xx): ";
    cin >> passageiro.cpf;

    while (true)
    {
        if (regex_match(passageiro.cpf, cpfValido))
        {
            break;
        }
        else
        {
            cout << "CPF inválido, por favor digite novamente: ";
            cin >> passageiro.cpf;
        }
    }

    for (Passageiro &it : passageiros)
    {
        if (it.cpf == passageiro.cpf)
        {
            cout << "CPF já cadastrado!" << endl;
            return;
        }
    }

    cout << "Informe o nome do passageiro a ser incluído: ";
    cin.ignore();
    getline(cin, passageiro.nome);

    cout << "Informe a data de nascimento do passageiro a ser incluído (da/mm/aaaa): ";
    cin >> passageiro.dataNascimento;

    while (true)
    {
        if (regex_match(passageiro.dataNascimento, dataValida))
        {
            break;
        }
        else
        {
            cout << "Data inválida, por favor digite novamente: ";
            cin >> passageiro.dataNascimento;
        }
    }

    if(calcularIdade(passageiro.dataNascimento) < 18) {
        cout << "Informe o número de autorização do passageiro: ";
        cin >> passageiro.numAutorizacao;

        for (Passageiro &it : passageiros)
        {
            if (it.numAutorizacao == passageiro.numAutorizacao)
            {
                cout << "Número de autorização já cadastrado!" << endl;
                return;
            }
        }
    } else {
        passageiro.numAutorizacao = "";
    }


    passageiros.push_back(passageiro);

    cout << endl <<"Passageiro cadastrado com sucesso!" << endl;
}

void excluirPassageiro(vector<Passageiro> &passageiros)
{
    string cpf;
    cout << "Digite o CPF do passageiro a ser excluído: ";
    cin >> cpf;

    for (auto it = passageiros.begin(); it != passageiros.end(); ++it)
    {
        if (it->cpf == cpf)
        {
            passageiros.erase(it);
            cout << "\nPassageiro excluído com sucesso!" << endl;
            return;
        }
    }

    cout << "Passageiro não encontrado." << endl;
}

void alteraPassageiro(vector<Passageiro> &passageiros)
{
    string cpf;
    char decisao;

    cout << "\nDeseja alterar o CPF? Se sim, pedimos para que insira os dados do passageiro novamente (S/N): ";
    cin >> decisao;

    if (decisao == 'S' ||decisao == 's')
    {
        excluirPassageiro(passageiros);
        criaPassageiro(passageiros);
        return;
    }

    cout << "Digite o CPF do passageiro que terá os dados alterados: ";
    cin >> cpf;

    for (Passageiro &it : passageiros)
    {
        if (it.cpf == cpf)
        {
            cout << "Deseja modificar o nome? (s/n): ";
            cin >> decisao;

            if (decisao == 's')
            {
                cout << "Novo Nome: ";
                cin.ignore();
                getline(cin, it.nome);
            }

            cout << "Deseja modificar a data de nascimento? (s/n): ";
            cin >> decisao;

            if (decisao == 's')
            {
                string dataAux = it.dataNascimento;
                cout << "Nova Data de Nascimento: ";
                cin >> it.dataNascimento;

                if(calcularIdade(dataAux) >= 18 && calcularIdade(it.dataNascimento) < 18) {
                    cout << "Agora o passageiro precisa de numero de autorizacao, insira por favor: ";
                    cin >> it.numAutorizacao;

                    for (Passageiro &itAutorizacao : passageiros)
                    {
                        if (itAutorizacao.numAutorizacao == it.numAutorizacao)
                        {
                            cout << "Numero de autorizacao ja cadastrado!" << endl;
                            return;
                        }
                    }
                }
            }

            if(it.numAutorizacao != "" || calcularIdade(it.dataNascimento) < 18) {
                cout << "Deseja mudar o numero de autorizacao? (s/n): ";
                cin >> decisao;

                if (decisao == 's')
                {
                    cout << "Novo Número de Autorizacao: ";
                    cin >> it.numAutorizacao;

                    for (Passageiro &itAutorizacao : passageiros)
                    {
                        if (itAutorizacao.numAutorizacao == it.numAutorizacao)
                        {
                            cout << "Numero de autorizacao ja cadastrado!" << endl;
                            return;
                        }
                    }
                }
            }

            cout << "Passageiro atualizado com sucesso!" << endl;
            return;
        }
    }

    cout << "Passageiro nao encontrado." << endl;
}

void listaPassageiro(vector<Passageiro> &passageiros)
{
    if (passageiros.empty())
    {
        cout << "\nNão existem passageiros cadastrados!" << endl;
        return;
    }
    cout << "\nLista de passageiros cadastrados:" << endl;
    for (Passageiro &it : passageiros)
    {
        if(it.numAutorizacao != "") {
            cout << "CPF: " << it.cpf << ", Nome: " << it.nome << ", Data de Nascimento: " << it.dataNascimento << ", Número de Autorização: " << 
            it.numAutorizacao << endl;
        } else {
            cout << "CPF: " << it.cpf << ", Nome: " << it.nome << ", Data de Nascimento: " << it.dataNascimento << endl;
        }
    }
}

void localizaPassageiro(vector<Passageiro> &passageiros)
{

    if (passageiros.empty())
    {
        cout << "\nA lista de passageiros está vazia." << endl;
        return;
    }

    string cpf;
    cout << "\nDigite o CPF do passageiro a ser localizado: ";
    cin >> cpf;

    for (Passageiro &it : passageiros)
    {
        if (it.cpf == cpf)
        {
            if(it.numAutorizacao != "") {
                cout << "\nDados do passageiro solicitado:" << endl;
                cout << "CPF: " << it.cpf << ", Nome: " << it.nome << ", Data de Nascimento: " << it.dataNascimento << ", Número de Autorização: " << 
                it.numAutorizacao << endl;
                return;
            } else {
                cout << "\nDados do passageiro solicitado:" << endl;
                cout << "CPF: " << it.cpf << ", Nome: " << it.nome << ", Data de Nascimento: " << it.dataNascimento << endl;
                return;
            }
            
        }
    }

    cout << "\nPassageiro não encontrado!" << endl;
}

void menuPassageiro(vector<Passageiro> &passageiros)
{
    cout << endl
         << "==== Gestão de passageiros ==== " << endl <<"Serviços disponíveis:" << endl;
    cout << "1. Criar passageiro" << endl;
    cout << "2. Excluir passageiro" << endl;
    cout << "3. Alterar passageiro (por CPF)" << endl;
    cout << "4. Listar passageiros" << endl;
    cout << "5. Localizar passageiro (por CPF)" << endl;
    cout << "0. Sair" << endl;
    cout << "Escolha uma opção: ";

    int opt;
    cin >> opt;

    switch (opt)
        {
        case 1:
            criaPassageiro(passageiros);
            break;
        case 2:
            excluirPassageiro(passageiros);
            break;
        case 3:
            alteraPassageiro(passageiros);
            break;
        case 4:
            listaPassageiro(passageiros);
            break;
        case 5:
            localizaPassageiro(passageiros);
            break;
        case 0:
            cout << "Programa finalizado!" << endl;
            return;
        default:
            cout << "Digite um valor válido!" << endl;
        }
}
