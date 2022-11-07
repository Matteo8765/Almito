﻿// premiacao.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <clocale>


using namespace std;

typedef struct PREMIO {
    int id;
    string nome;
    double preco;
    bool vendido;
} PREMIO;


int addFim();
int ope1(); // Inserir na posição K+1
int ope2();
int ope3();
int ope4();
int ope5();
int ope6();
int ope7();
int ope8();
int ope9();
int ope10();
int ope11(); // Imprimir o conteúdo da lista
int ope12();
int ope13();
int opcao;

const int N = 10;
PREMIO premios[N] = {
                        {1, "Celular", 1250.99, false},
                        {2, "Mouse Gamer", 250.70, false},
                        {3, "Pacote de M&Ms", 250.70, true}
                    };
int final = 2; // índice do último item da lista. Caso final seja -1, a lista é vazia


int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    cout << " 1- Para Inseir na Posição K+1 \n"
         << " 2- Para Procurar um nó por nome do prêmio e inserir um novo nó anterior ao nó encontrado \n"
         << " 3 - Procurar um nó por quantidade de prêmios disponível e alterar o conteúdo do nó encontrado \n"
         << " 4 - Consultar o nó anterior ao da posição k + 1 \n"
         << " 5 - Remover na posição k \n"
         << " 6 - Procurar um nó e remover o novo nó na posição anterior ao nó encontrado \n"
         << " 7 - Verificar se um prêmio pertence à lista e imprimir o conteúdo do nó anterior \n"
         << " 8 - Imprimir a quantidade de nós com preço maior que R$50,00 \n"
         << " 9 - Procurar um nó e alterar o conteúdo do nó posterior encontrado \n"
         << " 10 - Imprimir relatório dos prêmios vendidos e calcular no final o montante arrecadado \n"
         << " 11 - Imprimir o conteúdo da lista \n"
         << " 12 - Classificar a lista por ordem de quantidade de prêmios disponíveis \n"
         << " 13 - Imprimir a lista os nós que estão armazenados nos índices impares.\n";
         cout << "Digite a opção desejada: \n";
         cin >> opcao;
    switch(opcao){
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    case 7:
        break;
    case 8:
        break;
    case 9:
        break;
    case 10:
        break;
    case 11:
        break;
    case 12:
        break;
    case 13:
        break;
    }
    //ope11();
    addFim();
    //cout << endl << premios[final].nome << endl;
}


int addFim()
{
    if (final < N - 1) //verifica se há espaço na lista
    {
        final++;
        cout << "\nNome: ";

        getline(cin, premios[final].nome);
        cout << "\nPreço: ";
        cin >> premios[final].preco;
        cout << "\nID: ";
        cin >> premios[final].id;
        premios[final].vendido = false;
    }
    else cout << "A listagem máxima de prêmios já foi atingida\n";
    return 0;
}

int ope1() // Inserir na posição K+1
{
    int k, aux;
    char conf = 'N';
    PREMIO val; // variável temporária
    cout << "Você escolheu a operação 1: Inserir na posição K+1.\n";
    if (final < N - 1) //verifica se há espaço na lista
    {
        cout << "Insira K";
        cin >> k; // como o intuito é inserir na posição k+1, não é necessário fazer nenhuma operação para ajustar à lista, indexada em 0
        if (k >= 0 and k <= final)
        {
            cout << "\nNome: ";
            getline(cin, val.nome);
            cout << "\nPreço: ";
            cin >> val.preco;
            cout << "\nID: ";
            cin >> val.id;
            val.vendido = false;

            cout << "Você confirma a inserção dos dados? (S/N)";
            cin >> conf;
            conf = toupper(conf);
            if (conf == 'S')
            {
                final++;

            }
            else
            {
                cout << "Inserção não confirmada!/n";
            }
        }
        else
        {
            cout << "k+1 não pertence à lista!\n";
            return 1;
        }
    }
    else
    {
        cout << "A listagem máxima de prêmios já foi atingida\n";
        return 1;
    }
    return 0;
}

int ope11() // Imprimir o conteúdo da lista
{
    cout << "Você escolheu a operação 11: Imprimir o conteúdo da lista.\n";
    if (final > -1)
    {
        for (int i = 0; i <= final; i++)
        {
            cout << "------------------------------------------------------------------" << endl;
            cout << "ID: " << premios[i].id << endl;
            cout << "NOME: " << premios[i].nome << endl;
            cout << "PREÇO: " << premios[i].preco << endl;
            cout << "STATUS: ";
            if (premios[i].vendido) cout << "VENDIDO" << endl;
            else cout << "À VENDA" << endl;

        }
    }
    else cout << "Lista vazia!\n";
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
