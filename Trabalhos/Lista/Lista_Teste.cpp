#include<iostream>
using namespace std;

const int TAM = 10;

int lista[TAM];
int comprimento = 0;

void inserelista(int valor)
{
    int i, maior = NULL;
    if(comprimento == TAM)
    {
        cout << "\nLista Cheia";
        return;
    }    
    if(comprimento < TAM)
    {
        lista[comprimento] = valor;
    }    
    if(comprimento >= 1)
    {
        maior = lista[comprimento-1];
        if(maior < lista[comprimento])
        {
            maior = lista[comprimento];            
        }
    }    
    comprimento++;
    cout  << "\nValor " << valor << " inserido";
    cout << "\nMaior eh " << maior;
}

int main()
{
    inserelista(2);
    inserelista(5);
    inserelista(11);
    inserelista(9);
    inserelista(10);
    inserelista(15);
    inserelista(3);
    inserelista(20);
    inserelista(0);
}