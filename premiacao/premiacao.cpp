// premiacao.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>


using namespace std;

typedef struct PREMIO {
    string nome;
    float preco;
    int id;
    bool vendido;
} PREMIO;

int addFim();
int ope1();
int ope2();
int ope3();
int ope4();
int ope5();
int ope6();
int ope7();
int ope8();
int ope9();
int ope10();
int ope11();
int ope12();
int ope13();

int final = -1; // índice do último item daa lista. Caso final seja -1, a lista é vazia
const int N = 3;
PREMIO premios[N];

int main(void)
{



    cout << "Digite a opção desejada: ";
    cout << "\n 1- Para Inseir na Posição K+1, 2- Para Procurar um nó por nome do prêmio";

    addFim();
    cout << endl << premios[final].nome << endl;
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



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
