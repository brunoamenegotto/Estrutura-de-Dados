#include <iostream>
using namespace std;

const int TAM = 10;
int pilha[TAM];
int topo = -1;

void push (int valor)
{
    if (topo == TAM-1)
    {
        cout << "Pilha Cheia";
        return;
    }
    topo++;
    pilha[topo] = valor;
    cout << "Push realizado com Sucesso";
    cout << endl;
}

void pop ()
{
    if (topo == -1)
    {
        cout << "Pilha vazia";
        return;
    }
    topo--;
    cout << "Pop realizado com Sucesso";
    cout << endl;
}

void topoPilha(int valor)
{
    int i;
    if (topo == TAM - 1)
    {
        cout << "Pilha vazia";
        return;
    }
    cout << "Ultimo elemento da pilha: ";

        if (topo = TAM-1)
        {
            cout << pilha[topo] << " ";
        }
        cout << endl;
        return;
}

void imprimir ()
{
    int i;
    if (topo == -1)
    {
        cout << "Pilha vazia";
        return;
    }
    cout << "Pilha: ";
        for (i = 0; i < TAM; i++)
            cout << pilha[i] << " ";
            cout << endl;
        return;
}

int main()
{
    cout << "Informe os elementos do vetor: " << endl;
    for (topo = 0; topo<TAM; topo++)
        cin >> pilha[topo];
    push(topo);
    pop();
    topoPilha(topo);
    imprimir();
}
