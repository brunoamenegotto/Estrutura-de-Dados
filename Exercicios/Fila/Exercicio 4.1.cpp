#include<iostream>
using namespace std;

struct no
{
    int dado;
    struct no *prox;
};
struct no *inicio = NULL;
struct no *fim = NULL;

void inserir(int valor)
{
    struct no *novo;
    novo = new(struct no);
    novo -> dado = valor;
    novo -> prox = NULL;
    if(fim == NULL)
    {
        fim = novo;
        inicio = novo;
    }
    else
    {
        fim -> prox = novo;
        fim = novo;
    }
}

void imprimir()
{
    struct no *aux;
    if(inicio == NULL)
    {
        cout << "FILA VAZIA";
        return;
    }
    aux = inicio;
    while (aux!=NULL)
    {
        cout << aux -> dado << endl;
        aux = aux -> prox;
    }
}

int main()
{
    inserir(50);
    inserir(60);
    inserir(25);
    inserir(10);
    imprimir();
}
