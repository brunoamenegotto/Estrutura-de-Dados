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

void remover()
{
    struct no *aux;
    if(inicio == NULL)
    {
        cout << "Fila Vazia";
        return;
    }
    aux = inicio;
    inicio = inicio -> prox;
    if(inicio == NULL)
        fim = NULL;
    delete(aux);
    cout << "Sucesso na remocao" << endl;
}
void iniciofila()
{
    if(inicio == NULL)
    {
        cout << "FILA VAZIA";
        return;
    }
    cout << "INICIO: " << inicio -> dado << endl;

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
    inserir(5);
    inserir(10);
    inserir(15);
    inserir(20);
    inserir(25);
    remover();
    imprimir();
    iniciofila();
}
