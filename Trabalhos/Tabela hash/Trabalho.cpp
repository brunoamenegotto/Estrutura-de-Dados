#include<iostream>
#include<stdio.h>

using namespace std;

const int TAM = 5;
int chave, vetor[TAM], h, th, pos;

int espalha(int chave)
{
    return chave % TAM;
}
int reespalha(int pos)
{
    return (pos +1) % TAM;

}
void insere(int valor)
{
    int cont;
    if (cont == TAM)
    {
        cout << " Tabela Cheia";
        return;
    }
    h = espalha(valor);
    vetor[h] = valor;
    cont ++;
}

void imprimir()
{
    for (h = 0; h < TAM; h++)
    {
        cout << vetor[h] << " ";
    }
}

int main()
{
    insere(1);
    insere(2);
    insere(3);
    insere(4);
    insere(5);
    insere(6);
    imprimir();
}
