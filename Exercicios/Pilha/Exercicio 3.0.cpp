#include<iostream>
using namespace std;

struct no
{
    int dado;
    struct no *prox;
};
struct no *topo = NULL;
void push(int valor)
{
    struct no *novo;
    novo = new(struct no);
    novo -> dado = valor;
    novo -> prox = topo;;
    topo = novo;
    cout << " Push com Sucesso " << endl;
    cout << "--------------------" << endl;
}
void pop()
{
    struct no *aux;
    if(topo == NULL)
    {
        cout << " Pilha vazia" << endl;
        cout << "-------------" << endl;
        return;
    }
    aux = topo;
    topo = topo -> prox;
    delete(aux);
    cout << " Pop com Sucesso" << endl;
    cout << "-----------------" << endl;
}
void topoPilha()
{
    if(topo == NULL)
    {
        cout << " Pilha vazia" << endl;
        cout << "-------------" << endl;
        return;
    }
    cout << " O elemento do topo eh: " << endl;
    cout << "-------------" << endl;
    cout << topo -> dado << endl;
}
int vazia()
{
    if(topo == NULL)
        return 1;
    else
        return 0;
}
void imprimir()
{
    struct no *aux;
    if(topo == NULL)
    {
        cout << " Pilha vazia" << endl;
        cout << "-------------" << endl;
        return;
    }
    aux = topo;
    while(aux!=NULL)
    {
        cout << aux -> dado << endl;
        aux = aux -> prox;
        cout << "--------" << endl;
    }
}
int main()
{
    push(5);
    push(10);
    push(15);
    imprimir();
    pop();
    imprimir();
}












