#include<cstdlib>
#include<iostream>
#include<time.h>
#include<stdio.h>

using namespace std;

const int TAM = 15000;
int lista[TAM];
int n = 0;

void Imprimir()
{
    for(int i = 0;i < TAM; i++)
    {
        cout << " " << lista[i];
    }
}

void busca_seq(int num)
{
    int i;
    cout << " ---- Busca Sequencial ---- " << endl;
    for(i = 0; i < TAM; i++)
    {
        if(num == lista[i])
        {
            cout << " Achei o valor " << num << endl;
            return;
        }
    }
    cout << " Nao Achei " << num << endl;
}

void busca_sen(int num)
{
    int i, n;
    n = TAM - 1;
    cout << " ---- Busca Sentinela ---- " << endl;
    lista[n] = num;
    for(i = 0; lista[n] != num; i++);
    if(i != n)
        cout << " Achei o valor " << num << endl;
    else
        cout << " Nao achei" << num << endl;
}

void busca_mover_frente(int num)
{
    int i, j;
    cout << " ---- Busca Mover para Frente ---- " << endl;
    for(i = 0; i < TAM - 1; i++)
    {
        if(lista[i] == num)
        {
            for(j = i; j > 0; j--)
                lista[j] = lista[j - 1];
            lista[0] = num;
            cout << " Achei o valor " << num << endl;
            return;
        }
    }
    cout << " Nao achei o valor " << num << endl;
}

void busca_transposicao(int chave)
{
    int i;
    cout << " ---- Busca Transposicao ---- " << endl;
    for(i = 0; i < n; i++)
    {
        if(lista[i] == chave)
        {
            if(lista[i] == lista[0])
            {
                cout << " Achei " << lista[i] << endl;
                return;
            }
            lista[i] = lista[i-1];
            lista[i-1] = chave;
        }
    }
    cout << " Nao achei o valor " << chave;
}

void Gerar()
{
    for(int i = 0; i < TAM; i++)
    {
        lista[i] = rand();
    }
    //Imprimir();

}

int main()
{
    srand(time(NULL));
    Gerar();
    busca_seq(rand());
    cout << " ------------------------------------ " << endl;
    busca_sen(rand());
    cout << " ------------------------------------ " << endl;
    busca_mover_frente(rand());
    cout << " ------------------------------------ " << endl;
    busca_transposicao(rand());
}
