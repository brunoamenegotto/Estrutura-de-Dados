#include<iostream>
#include<stdio.h>
using namespace std;

const int TAM = 6;
int matriz[TAM][TAM];
int vertice[TAM];
int contadorVertice = 0;

struct no
{
    int destino;
    struct no *prox;
};
struct no *aresta[TAM];

void insereVertice(int valor)
{
    int i, j;
    if (contadorVertice == TAM)
    {
        cout << " Nao pode mais inserir vertices" << endl;
        return;
    }

    for (i = 0; i < contadorVertice; i++)
    {
        if (vertice[i] == valor)
        {
            cout << " Vertice repetido";
            return;
        }
    }
    vertice[i] = valor;
    contadorVertice++;
    cout << " Vertice " << valor << " inserido com sucesso" << endl;
}

void insereAresta(int origem, int destino)
{
    int i, j;
    struct no *atual, *novo, *anterior;

    for (i = 0; i < contadorVertice; i++)
    {
        if(vertice[i] == origem)
        {
            cout << " Origem: " << origem << endl;
            break;
        }
    }
    if(i == contadorVertice)
    {
        cout << " Nao achei vertice de origem: " << origem << endl;
        return;
    }

    for (j = 0; j < contadorVertice; j++)
    {
        if(vertice[j] == destino)
        {
            cout << " Destino: " << destino << endl;
            break;
        }
    }
    if(j == contadorVertice)
    {
        cout << " Nao achei vertice de destino: " << destino << endl;
        return;
    }
    matriz[i][j] = 1;
    cout << " Aresta inserida" << endl;

    atual = aresta[i];
    while (atual != NULL)
    {
        if(atual -> destino == destino)
        {
            cout << " Aresta repetida" << endl;
            return;
        }
        anterior = atual;
        atual = atual -> prox;
    }
    novo = new(struct no);
    novo -> destino = destino;
    novo -> prox = NULL;
    if (atual == aresta[i])
        aresta[i] = novo;
    else
        anterior -> prox = novo;
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

    struct no *atual, *novo, *anterior;
    atual = aresta[i];
    while (atual != NULL)
    {
        if(atual -> destino == destino)
        {
            if(atual == aresta[i])
                aresta[i] = atual -> prox;
            else
                anterior -> prox = atual -> prox;
            delete (atual);
            cout << " Aresta removida" << endl;
        }
        anterior = atual;
        atual = atual -> prox;
    }
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
    insereVertice(13);
    insereVertice(11);
    insereVertice(23);
    insereAresta(10,11);
    insereAresta(11,13);
    insereAresta(11,23);
    insereAresta(11,23);
    imprimir();
    removeAresta(10,11);
    imprimir();
    insereVertice(23);
    imprimir();
}
