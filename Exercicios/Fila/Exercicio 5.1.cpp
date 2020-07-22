#include<iostream>
using namespace std;
struct no
{
    int dado;
    struct no *prox;
};

struct no *inicio = NULL;
struct no *fim = NULL;

void insereDeque(int valor, int lado)
{
    struct no *novo;
    novo = new(struct no);
    novo -> dado = valor;
    novo -> prox = NULL;
    if(fim == NULL)
    {
        inicio = novo;
        fim = novo;
        return;
    }
    if(lado == 1)
    {
        fim -> prox = novo;
        fim = novo;
    }
    else
    {
        novo -> prox = inicio;
        inicio = novo;
    }
}
void removeDeque(int lado)
{
	struct no *aux;

   if (inicio == NULL) {
   	  cout << "Fila vazia" << endl;
   	  return;
   }
   aux = inicio;
   if (lado==0)
         inicio = inicio->prox;
      else {
           while (aux->prox!=fim && aux->prox!=NULL)
                 aux=aux->prox;

           if (aux->prox!=NULL) {
              fim=aux;
              fim->prox=NULL;
              aux=aux->prox;
           } else fim=NULL;
      }
      if (inicio==NULL || fim==NULL) {
         	fim=NULL;
         	inicio=NULL;
      }
      delete(aux);
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
    insereDeque(50,0);
    insereDeque(60,0);
    insereDeque(65,0);
    insereDeque(25,1);
    removeDeque(0);
    imprimir();
}
