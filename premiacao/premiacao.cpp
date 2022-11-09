// premiacao.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
    int quantidade;
    int vendidos;
} PREMIO;



int menuInicio();
int encerrar();

int ope1(); // Inserir na posição K+1
int ope2(); // Procurar nó por nome e inserir novo nó na posição anterior ao nó encontrado
int ope3(); // Procurar um nó por quantidade de prêmios disponível e alterar o conteúdo do nó encontrado
int ope4(); // Consultar nó anterior à posição K+1
int ope5(); // Remover na posição k
int ope6(); // Procurar um nó por nome e remover o nó na posição anterior ao nó encontrado
int ope7();
int ope8();
int ope9();
int ope10();
int ope11(); // Imprimir o conteúdo da lista
int ope12();
int ope13(); // Imprimir os nós de índice ímpar da lista

int opcao;

const int N = 10;
PREMIO premios[N] = {
                        {1, "Celular", 1250.99, 2, 0},
                        {2, "Mouse Gamer", 250.70, 3, 2},
                        {3, "Pacote de M&Ms", 250.70, 23, 40}
                    };
int final = 2; // índice do último item da lista. Caso final seja -1, a lista é vazia


int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    menuInicio();
}

int menuInicio()
{

    cout    << " 0 - Para encerrar o Programa\n"
            << " 1 - Para Inserir na Posição K+1 \n"
            << " 2 - Para Procurar um nó por nome do prêmio e inserir um novo nó anterior ao nó encontrado \n"
            << " 3 - Procurar um nó por quantidade de prêmios disponível e alterar o conteúdo do nó encontrado \n"
            << " 4 - Consultar o nó anterior ao da posição k + 1 \n"
            << " 5 - Remover na posição k \n"
            << " 6 - Procurar um nó por nome e remover o nó na posição anterior ao nó encontrado \n"
            << " 7 - Verificar se um prêmio pertence à lista e imprimir o conteúdo do nó anterior \n"
            << " 8 - Imprimir a quantidade de nós com preço maior que R$50,00 \n"
            << " 9 - Procurar um nó e alterar o conteúdo do nó posterior encontrado \n"
            << " 10 - Imprimir relatório dos prêmios vendidos e calcular no final o montante arrecadado \n"
            << " 11 - Imprimir o conteúdo da lista \n"
            << " 12 - Classificar a lista por ordem de quantidade de prêmios disponíveis \n"
            << " 13 - Imprimir a lista os nós que estão armazenados nos índices impares.\n";
    cout << "Digite a opção desejada: \n";
    cin >> opcao;
    switch (opcao) {
    case 0:
        encerrar();
        return 0;
        break;
    case 1:
        ope1();
        break;
    case 2:
        ope2();
        break;
    case 3:
        ope3();
        break;
    case 4:
        ope4();
        break;
    case 5:
        ope5();
        break;
    case 6:
        ope6();
        break;
    case 7:
        //ope7();
        break;
    case 8:
        //ope8();
        break;
    case 9:
        //ope9();
        break;
    case 10:
        //ope10();
        break;
    case 11:
        ope11();
        break;
    case 12:
        //ope12();
        break;
    case 13:
        ope13();
        break;
    }
    menuInicio(); //Ao terminar de fazer tudo, a função chama a si mesma novamente para que o programa continue ativo
    return 0;
}

int encerrar()
{
    cout << "Você decidiu encerrar o Programa. Até Breve! \n\n";
    return 0;
}



int ope1() // Inserir na posição K+1
{
    int k;
    char conf = 'N';
    PREMIO val; // variável temporária
    cout << "Você escolheu a operação 1: Inserir na posição K+1.\n";
    if (final < N - 1) //verifica se há espaço na lista
    {
        cout << "Insira K: ";
        cin >> k; // como o intuito é inserir na posição k+1, não é necessário fazer nenhuma operação para ajustar à lista, indexada em 0
        if (k >= 0 and k <= final)
        {
            cout << "\nNome: ";
            getline(cin >> ws, val.nome);
            cout << "\nPreço: ";
            cin >> val.preco;
            cout << "\nID: ";
            cin >> val.id;
            cout << "\nQuantas unidades deste prêmio estão disponíveis? ";
            cin >> val.quantidade;
            cout << "\nQuantas unidades deste prêmio já foram vendidas? ";
            cin >> val.vendidos;

            cout << "Você confirma a inserção dos dados? (S/N)";
            cin >> conf;
            conf = toupper(conf);
            if (conf == 'S')
            {
                final++;
                for (int aux = final; aux > k; aux--)
                {
                    premios[aux] = premios[aux - 1];
                }
                premios[k] = val;
                cout << "Inserção Concluída com sucesso!\n\n";
                return 0;
            }
            else
            {
                cout << "Inserção não confirmada!\n\n";
                return 1;
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
        cout << "A listagem máxima de prêmios já foi atingida\n\n";
        return 1;
    }
    return 0;
}

int ope2() // Procurar nó por nome e inserir novo nó na posição anterior ao nó encontrado
{
    string nome;
    int indice;
    bool encontrado = false;
    char conf = 'N';
    PREMIO val; // variável temporária
    cout << "Você escolheu a operação 2: Procurar nó por nome e inserir novo nó na posição anterior ao nó encontrado.\n";
    if (final < N - 1) //verifica se há espaço na lista
    {
        if (final > -1)
        {
            cout << "Insira o nome do Nó que você deseja procurar: ";
            getline(cin >> ws, nome);
            for (int i = 0; i <= final; i++)
            {
                if (premios[i].nome.compare(nome) == 0)
                {
                    encontrado = true;
                    indice = i;
                    break;
                }
            }
            if (encontrado)
            {
                cout << "\nNó encontrado ! Por favor insira as informações para o novo nó:\n";
                cout << "\nNome: ";
                getline(cin >> ws, val.nome);
                cout << "\nPreço: ";
                cin >> val.preco;
                cout << "\nID: ";
                cin >> val.id;
                cout << "\nQuantas unidades deste prêmio estão disponíveis? ";
                cin >> val.quantidade;
                cout << "\nQuantas unidades deste prêmio já foram vendidas? ";
                cin >> val.vendidos;


                cout << "Você confirma a inserção dos dados? (S/N)";
                cin >> conf;
                conf = toupper(conf);
                if (conf == 'S')
                {
                    final++;
                    for (int aux = final; aux > indice; aux--)
                    {
                        premios[aux] = premios[aux - 1];
                    }
                    premios[indice] = val;
                    cout << "Inserção Concluída com sucesso!\n\n";
                    return 0;
                }
                else
                {
                    cout << "Inserção não confirmada!\n\n";
                    return 1;
                }
            }
            else
            {
                cout << nome << " não pertence à lista!\n\n";

                return 1;
            }
        }
        else
        {
            cout << "Lista vazia!\n\n";
            return 1;
        }
    }
    else
    {
        cout << "A listagem máxima de prêmios já foi atingida\n\n";
        return 1;
    }
    return 0;
}

int ope3() // Procurar um nó por quantidade de prêmios disponível e alterar o conteúdo do nó encontrado
{

    int quant;
    int indice;
    bool encontrado = false;
    char conf = 'N';
    PREMIO val; // variável temporária
    cout << "Você escolheu a operação 3: Procurar um nó por quantidade de prêmios disponível e alterar o conteúdo do nó encontrado.\n";

    if (final > -1)
    {
        cout << "Insira a quantidade de premios disponíveis que você deseja procurar: ";
        cin >> quant;
        for (int i = 0; i <= final; i++)
        {
            if (premios[i].quantidade == quant)
            {
                encontrado = true;
                indice = i;
                break;
            }
        }
        if (encontrado)
        {
            cout << "\nNó encontrado ! Por favor insira as novas informações para alterar o nó:\n";
            cout << "\nNome: ";
            getline(cin >> ws, val.nome);
            cout << "\nPreço: ";
            cin >> val.preco;
            cout << "\nID: ";
            cin >> val.id;
            cout << "\nQuantas unidades deste prêmio estão disponíveis? ";
            cin >> val.quantidade;
            cout << "\nQuantas unidades deste prêmio já foram vendidas? ";
            cin >> val.vendidos;

            cout << "Você confirma a alteração dos dados? (S/N)";
            cin >> conf;
            conf = toupper(conf);
            if (conf == 'S')
            {
                premios[indice] = val;
                cout << "Alteração Concluída com sucesso!\n\n";
                return 0;
            }
            else
            {
                cout << "Alteração não confirmada!\n\n";
                return 1;
            }
        }
        else
        {
            cout << "Não há nenhum nó com " << quant << " prêmios disponíveis na lista!\n\n";

            return 1;
        }
    }
    else
    {
        cout << "Lista vazia!\n\n";
        return 1;
    }

    return 0;
}

int ope4() // Consultar nó anterior à posição K+1
{
    int k;
    char conf = 'N';
    cout << "Você escolheu a operação 4: Consultar o nó anterior à posição K+1.\n"; //É o mesmo que consultar o nó na posição K
    
    cout << "Insira K: ";
    cin >> k;
    k--; //é necessario reduzir k em 1, já que a posição de um nó é igual ao seu índex somado a um.
    if (k >= 0 and k <= final)
    {
        cout << "\n\n"
             << "ÍNDICE: " << k << endl
             << "POSIÇÃO: " << k + 1 << endl
             << "ID: " << premios[k].id << endl
             << "NOME: " << premios[k].nome << endl
             << "PREÇO: " << premios[k].preco << endl
             << "QUANTIDADE DISPONÍVEL: ";
        if (premios[k].quantidade > 0)
        {
            cout << premios[k].quantidade << endl;
        }
        else cout << "ESGOTADO" << endl;
        cout << "QUANTIDADE DE PREMIOS VENDIDOS: " << premios[k].vendidos << endl;
    }
    else
    {
        cout << "A posição k não pertence à lista!\n";
        return 1;
    }
    
    return 0;
}

int ope5() // Remover na posição k
{
    cout << "Você escolheu a operação 5: Remover na posição k.\n";

    int k;
    char conf = 'N';

    cout << "Insira K: ";
    cin >> k;
    k--; //é necessario reduzir k em 1, já que a posição de um nó é igual ao seu índex somado a um.
    if (final > -1)
    {
        if (k >= 0 and k <= final)
        {
            cout << "\n\n"
                << "ÍNDICE: " << k << endl
                << "POSIÇÃO: " << k + 1 << endl
                << "ID: " << premios[k].id << endl
                << "NOME: " << premios[k].nome << endl
                << "PREÇO: " << premios[k].preco << endl
                << "QUANTIDADE DISPONÍVEL: ";
            if (premios[k].quantidade > 0)
            {
                cout << premios[k].quantidade << endl;
            }
            else cout << "ESGOTADO" << endl;
            cout << "QUANTIDADE DE PREMIOS VENDIDOS: " << premios[k].vendidos << "\n\n";

            cout << "\n\nVocê confirma a Remoção deste nó? (S/N)";
            cin >> conf;
            conf = toupper(conf);
            if (conf == 'S')
            {
                for (int i = k; i < final; i++)
                {
                    premios[i] = premios[i + 1];
                }
                final--;
                cout << "Remoção Concluída com sucesso!\n\n";
                return 0;
            }
            else
            {
                cout << "Remoção não confirmada!\n\n";
                return 1;
            }
        }
        else
        {
            cout << "A posição k não pertence à lista!\n";
            return 1;
        }      
    }
    else
    {
        cout << "Lista vazia!\n\n";
        return 1;
    }
    
    return 0;
}

int ope6() // Procurar um nó por nome e remover o nó na posição anterior ao nó encontrado
{
    string nome;
    int indice;
    bool encontrado = false;
    char conf = 'N';
    PREMIO val; // variável temporária
    cout << "Você escolheu a operação 6: Procurar um nó por nome e remover o nó na posição anterior ao nó encontrado.\n\n";
    
    if (final > -1)
    {
        cout << "Insira o nome do Nó que você deseja procurar: ";
        getline(cin >> ws, nome);
        for (int i = 0; i <= final; i++)
        {
            if (premios[i].nome.compare(nome) == 0)
            {
                encontrado = true;
                indice = i;
                break;
            }
        }
        if (encontrado)
        {
            if (indice > 0)
            {
                indice--;
                cout << "\nNó encontrado !\n Seguem as informações do nó anterior ao encontrado:\n\n"
                    << "ÍNDICE: " << indice << endl
                    << "POSIÇÃO: " << indice + 1 << endl
                    << "ID: " << premios[indice].id << endl
                    << "NOME: " << premios[indice].nome << endl
                    << "PREÇO: " << premios[indice].preco << endl
                    << "QUANTIDADE DISPONÍVEL: ";
                if (premios[indice].quantidade > 0)
                {
                    cout << premios[indice].quantidade << endl;
                }
                else cout << "ESGOTADO" << endl;
                cout << "QUANTIDADE DE PREMIOS VENDIDOS: " << premios[indice].vendidos << "\n\n";

                cout << "Você confirma a Remoção deste nó? (S/N)";
                cin >> conf;
                conf = toupper(conf);
                if (conf == 'S')
                {
                    for (int i = indice; i < final; i++)
                    {
                        premios[i] = premios[i + 1];
                    }
                    final--;
                    cout << "Remoção Concluída com sucesso!\n\n";
                    return 0;
                }
                else
                {
                    cout << "Remoção não confirmada!\n\n";
                    return 1;
                }
            }
            else
            {
                cout << "O nó que você procurou é o primeiro da lista, portanto não há nenhum nó antes dele para remover!\n\n";
                return 1;
            }
            
        }
        else
        {
            cout << nome << " não pertence à lista!\n\n";

            return 1;
        }
    }
    else
    {
        cout << "Lista vazia!\n\n";
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
            cout << "ÍNDICE: " << i << endl;
            cout << "POSIÇÃO: " << i + 1 << endl;
            cout << "ID: " << premios[i].id << endl;
            cout << "NOME: " << premios[i].nome << endl;
            cout << "PREÇO: " << premios[i].preco << endl;
            cout << "QUANTIDADE DISPONÍVEL: ";
            if (premios[i].quantidade > 0)
            {
                cout << premios[i].quantidade << endl;
            }
            else cout << "ESGOTADO" << endl;
            cout << "QUANTIDADE DE PREMIOS VENDIDOS: " << premios[i].vendidos << endl;

        }
        cout << "------------------------------------------------------------------\n\n\n";
    }
    else
    {
        cout << "Lista vazia!\n\n";
        return 1;
    }
    return 0;
}

int ope13() // Imprimir os nós de índice ímpar da lista
{
    cout << "Você escolheu a operação 13: Imprimir os nós de índice ímpar da lista.\n";
    if (final > 0)
    {
        for (int i = 0; i <= final; i++)
        {
            if (i % 2)
            {
                cout << "------------------------------------------------------------------" << endl;
                cout << "ÍNDICE: " << i << endl;
                cout << "POSIÇÃO: " << i+1 << endl;
                cout << "ID: " << premios[i].id << endl;
                cout << "NOME: " << premios[i].nome << endl;
                cout << "PREÇO: " << premios[i].preco << endl;
                cout << "QUANTIDADE DISPONÍVEL: ";
                if (premios[i].quantidade > 0)
                {
                    cout << premios[i].quantidade << endl;
                }
                else cout << "ESGOTADO" << endl;
                cout << "QUANTIDADE DE PREMIOS VENDIDOS: " << premios[i].vendidos << endl;
            }
        }
        cout << "------------------------------------------------------------------\n\n\n";
    }
    else
    {
        cout << "Não há nós de índice ímpar na lista!\n\n";
        return 1;
    }
    return 0;
}

