#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

const int TAM = 7;
int fila[TAM];
int inicio = 0;
int fim = 0;
int contador = 0;

void inserir(int valor)
{
    if (contador == TAM)
    {
        cout << "FILA CHEIA";
        return;
    }
    fila[fim] = valor;
    if (fim == TAM - 1)
        fim = 0;
    else
        fim ++;
    contador ++;
}
void remover()
{
    if (contador == 0)
    {
        cout << "FILA VAZIA" << endl;
        return;
    }
    if (inicio == TAM - 1)
        inicio = 0;
    else
        inicio ++;
    contador --;
}
void imprimir()
{
    int i, j;
    if(contador == 0)
    {
        cout << "FILA VAZIA" << endl;
        return;
    }
    j = inicio;
    cout << endl;
    for(i=0; i < contador; i++)
    {
        cout << fila[j] << endl;
        if(j==TAM-1)
            j=0;
        else
            j++;
        cout << endl;
    }
}
int main()
{
    inserir(5);
    inserir(10);
    inserir(6);
    imprimir();
    remover();
    imprimir();
    system("pause");
}
