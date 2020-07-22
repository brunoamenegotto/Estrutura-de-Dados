#include<iostream>
#include<cstdio>
#include<cstring>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct no
{
    int dado;
    struct no *prox;
};

struct no *lista = NULL;
void insereLista(int valor)
{
    struct no *atual;
    struct no *anterior;
    struct no *novo;
    novo = new(struct no);
    novo -> dado = valor;
    atual = lista;
    while (atual != NULL && atual -> dado < valor)
    {
        anterior = atual;
        atual = atual -> prox;
    }
    if (atual == lista)
    {
        lista = novo;
        novo -> prox = atual;
    }
    else
    {
        anterior -> prox = novo;
        novo -> prox = atual;
    }
    cout << "\nElemento " << valor << " inserido com sucesso";
}
void removeLista(int posicao)
{
    struct no *atual;
    struct no *aux;
    int cont = 1;
    if(lista == NULL)
    {
        cout << "\nLista Vazia";
        return;
    }
    atual = lista;
    while(atual != NULL && cont <= posicao)
    {
        atual = atual -> prox;
        cont++;
    }
    if(posicao < 0 || atual == NULL)
    {
        cout << "\nPosicao " << posicao << " para remocao nao existe";
        return;
    }
    if(posicao == 0)
    {
        aux = atual;
        lista = lista -> prox;
    }
    else
    {
        aux = atual -> prox;
        atual -> prox = aux -> prox;
    }
    delete(aux);
    cout << "\nElemento da posicao " << posicao << " removido";
}
void recuperaLista(int posicao)
{
    struct no *atual;
    int cont = 0;
    atual = lista;
    while(atual != NULL && cont <= posicao)
    {
        atual = atual -> prox;
        cont ++;
    }
    if(posicao < 0 || atual == NULL)
    {
        cout << "\nPosicao " << posicao << " para a recuperacao nao existe";
        return;
    }
    cout << "\nElemento na posicao " << posicao << " foi recuperado seu valor eh " << atual -> dado;
}
void removeValor(int valor)
{
    struct no *atual;
    struct no *aux;
    int cont = 0;
    if(lista == NULL)
    {
        cout << "\nLista Vazia";
        return;
    }
    atual = lista;
    while(atual != NULL && cont <= valor)
    {
        if(atual -> dado == valor)
        {
            if(atual == lista)
            {
                lista = lista -> prox;
            }
            else
            {
                aux -> prox = atual -> prox;
            }
            delete(aux);
            cout << "\nElemento " << valor << " removido";
            return;
        }
        aux = atual;
        atual = atual -> prox;
        cont++;
    }
    cout << "\nElemento " << valor << " para a nao existe";

}
void imprimir()
{
    struct no *aux;
    if(lista == NULL)
    {
        cout << "\nLista Vazia";
        return;
    }
    aux = lista;
    cout << "\nLista eh: ";
    while (aux!=NULL)
    {
        cout << aux -> dado << " ";
        aux = aux -> prox;
    }
}

void maiorValor(no *lista)
{
    int maior = lista->dado;
    while(lista!=NULL)
    {
        if(lista->dado > maior)
        {
            maior = lista->dado;
        }
        lista = lista->prox;
    }
    cout << "O maior valor inserido foi " << maior;
}

int main()
{
    insereLista(1);
    insereLista(2);
    insereLista(3);
    insereLista(5);
    insereLista(10);
    insereLista(4);
    insereLista(15);
    insereLista(55);
    imprimir();
    removeLista(4);
    imprimir();
    maiorValor(lista);
    //system ("pause");
}
