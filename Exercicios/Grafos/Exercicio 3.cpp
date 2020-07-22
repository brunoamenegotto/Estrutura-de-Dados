#include<iostream>
#include<stdio.h>
using namespace std;

const int TAM = 6;
int matriz[TAM][TAM];
int vertice[TAM];
int visita[TAM];
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

void DFSR(int vert)
{
    int v;
    visita[vert] = 1;
    cout << vertice[vert] << " ";
    for (v = 0; v < contadorVertice; v++)
        if(matriz[vert][v] == 1 && visita[v] == 0)
            DFSR(v);
}

void DFS()
{
    int v;
    for (v = 0; v < contadorVertice; v++)
        visita[v] = 0;
    for (v = 0; v < contadorVertice; v++)
        if (visita[v] == 0)
            DFSR(v);
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
    insereVertice(20);
    insereVertice(30);
    insereVertice(40);
    insereVertice(50);
    insereAresta(10,20);
    insereAresta(20,30);
    insereAresta(10,40);
    insereAresta(40,30);
    insereAresta(10,50);
    imprimir();
    DFS();
}
