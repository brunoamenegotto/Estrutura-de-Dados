#include<iostream>
#include<stdio.h>
using namespace std;

const int TAM = 6;
int matriz[TAM][TAM];
int vertice[TAM];
int contadorVertice = 0;

void insereVertice(int valor)
{
    int i, j;
    if (contadorVertice == TAM)
    {
        cout << "Nao pode mais inserir vertices" << endl;
        return;
    }

    for (i = 0; i < contadorVertice; i++)
    {
        if (vertice[i] == valor)
        {
            cout << "Vertice repetido";
            return;
        }
    }
    vertice[i] = valor;
    contadorVertice++;
    cout << "Vertice inserido com sucesso" << endl;
}

void insereAresta(int origem, int destino)
{
    int i, j;
    for (i = 0; i < contadorVertice; i++)
    {
        if(vertice[i] == origem)
        {
            cout << "Achou origem" << endl;
            break;
        }
    }
    if(i == contadorVertice)
    {
        cout << "Nao achei vertice de origem" << endl;
        return;
    }

    for (j = 0; j < contadorVertice; j++)
    {
        if(vertice[j] == destino)
        {
            cout << "Achou destino" << endl;
            break;
        }
    }
    if(j == contadorVertice)
    {
        cout << "Nao achei vertice de destino" << endl;
        return;
    }
    matriz[i][j] = 1;
    cout << "Aresta inserida" << endl;
}

void haAresta(int origem, int destino)
{
    int i, j, k;
    for (i = 0; i < contadorVertice; i++)
    {
        if(vertice[i] == origem)
        {
            cout << "Achou origem" << endl;
            break;
        }
    }
    if(i == contadorVertice)
    {
        cout << "Nao achei vertice de origem" << endl;
        return;
    }

    for (j = 0; j < contadorVertice; j++)
    {
        if(vertice[j] == destino)
        {
            cout << "Achou destino" << endl;
            break;
        }
    }
    if(j == contadorVertice)
    {
        cout << "Nao achei vertice de destino" << endl;
        return;
    }

    cout << "aresta -> " << "< " << origem << " " << destino << " >" << endl;
}

void removeAresta(int origem, int destino)
{
    int i, j;
    for (i = 0; i < contadorVertice; i++)
    {
        if(vertice[i] == origem)
        {
            break;
        }
    }
    if(i == contadorVertice)
    {
        cout << "Nao achei vertice de origem" << endl;
        return;
    }

    for (j = 0; j < contadorVertice; j++)
    {
        if(vertice[j] == destino)
        {
            break;
        }
    }
    if(j == contadorVertice)
    {
        cout << "Nao achei vertice de destino" << endl;
        return;
    }
    matriz[i][j] = 0;
    cout << "Aresta removida" << endl;
}

void imprimir()
{
    int i, j;
    for (i = 0; i < TAM; i++)
    {
        for (j = 0; j < TAM; j++)
        {
            cout << matriz[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    insereVertice(10);
    insereVertice(7);
    insereVertice(20);
    insereVertice(12);
    insereAresta(7,10);
    insereAresta(10,20);
    insereAresta(20,7);
    insereAresta(10,12);
    imprimir();
    removeAresta(20,7);
    imprimir();
}
