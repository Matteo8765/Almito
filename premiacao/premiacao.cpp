// premiacao.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "definicao.h"
//#include "saleh.h"
//#include "spera.h"
//#include "vecchia.h"

using namespace std;

typedef struct PREMIO {
    string nome;
    float preco;
    int id;
    bool vendido;
} PREMIO;

int addFim();

int final = -1; // �ndice do �ltimo item da lista. Caso final seja -1, a lista � vazia
const int N = 3;
PREMIO premios[N];

int main(void)
{
    addFim();
    cout << endl << premios[final].nome << endl;
}


int addFim()
{
    if (final < N - 1) //verifica se h� espa�o na lista
    {
        final++;
        cout << "\nNome: ";
        std::cin >> premios[final].nome; // � necess�rio colocar std:: antes de cin, j� que cin � de um namespace, e string e vetor s�o de outro;
        cout << "\nPre�o: ";
        std::cin >> premios[final].preco;
        cout << "\nID: ";
        std::cin >> premios[final].id;
        premios[final].vendido = false;
    }
    else cout << "A listagem m�xima de pr�mios j� foi atingida\n";
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
