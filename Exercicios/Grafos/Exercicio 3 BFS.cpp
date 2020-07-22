#include<iostream>
#include<stdio.h>
using namespace std;

const int TAM = 6;
int matriz[TAM][TAM];
int vertice[TAM];
int visita[TAM];
int fila[TAM];
int contadorVertice = 0;
int contador = 0;
int inicio = 0;
int fim = 0;

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

int inicioFila()
{
    return inicio;
}

int vazia()
{
    if(contador == 0)
        return 1;
    else
        return 0;
}

int removeFila()
{
    if (contador == 0)
    {
        vazia();
    }
    if (inicio == TAM - 1)
        inicio = 0;
    else
        inicio ++;
    contador --;
    return inicioFila();
}

void insereFila(int valor)
{
    fila[fim] = valor;
    if (fim == TAM - 1)
        fim = 0;
    else
        fim ++;
    contador ++;
}

void BFSI(int vert)
{
    int v, a;
    visita[vert] = 1;
    cout << vertice[vert] << " ";
    insereFila(vert);
    while (!vazia())
    {
        v = removeFila();
        for (a = 0; a < contadorVertice; a++)
            if(matriz[v][a] == 1 && visita[a] == 0)
            {
                cout << vertice[a] << " ";
                visita[a] == 1;
                insereFila(a);
            }
    }
}

void BFS()
{
    int v;
    for (v = 0; v < contadorVertice; v++)
        visita[v] = 0;
    for (v = 0; v < contadorVertice; v++)
        if (visita[v] == 0)
            BFSI(v);
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
    BFS();
}
