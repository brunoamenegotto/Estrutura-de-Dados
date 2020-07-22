#include<iostream>
#include <stdlib.h>
using namespace std;

struct no
{
    struct no *dir;
    struct no *esq;
    char dado;
};

struct no *raiz = NULL;

void em_ordem(struct no *atual)
{
    if(atual != NULL)
    {
        em_ordem(atual -> esq);
        cout << atual -> dado << " ";
        em_ordem(atual -> dir);
    }
}

void pos_ordem(struct no *atual)
{
    if(atual != NULL)
    {
        pos_ordem(atual -> esq);
        pos_ordem(atual -> dir);
        cout << atual -> dado << " ";
    }
}

void pre_ordem(struct no *atual)
{
    if(atual != NULL)
    {
        cout << atual -> dado << " ";
        pre_ordem(atual -> esq);
        pre_ordem(atual -> dir);
    }
}

void insere(int valor)
{
    struct no *atual;
    struct no *anterior;
    struct no *novo;

    novo = new(struct no);

    novo -> esq = NULL;
    novo -> dir = NULL;
    novo -> dado = valor;

    if(raiz == NULL)
    {
        raiz = novo;
        return;
    }

    atual = raiz;
    while(atual != NULL)
    {
        anterior = atual;
        if(atual -> dado > valor)
        {
            atual = atual -> esq;
        }
        else
        {
            atual = atual -> dir;
        }
    }
    if(anterior -> dado > valor)
    {
        anterior -> esq = novo;
    }
    else
    {
        anterior -> dir = novo;
    }
}

void busca(int valor)
{
    struct no *atual;
    atual = raiz;
    while(atual != NULL)
    {
        if(valor == atual -> dado)
        {
            cout << "\nAchou o valor " << valor;
            return;
        }
        if(valor < atual -> dado)
        {
            atual = atual -> esq;
        }
        else
        {
            atual = atual -> dir;
        }
        if(atual -> esq == NULL && atual -> dir == NULL)
        {
            cout << "\nO valor esta na folha";
        }
    }
    if(atual == NULL)
    {
        cout << "\nNao achou o valor " << valor;
    }
}

int main()
{
    insere('c');
    insere('f');
    insere('a');
    insere('h');
    cout << "Em Ordem: ";
    em_ordem(raiz);
    cout << "\n";
    cout << "Pos Ordem: ";
    pos_ordem(raiz);
    cout << "\n";
    cout << "Pre Ordem: ";
    pre_ordem(raiz);
    system("pause");
}
