#include<cstdlib>
#include<time.h>
#include<iostream>
#include<stdio.h>

using namespace std;

const int TAM = 15000;
const int rep = 5;
int lista[TAM];
int *vet;
float constante = 0, media_operacoes, operacoes = 0;

void Imprimir()
{
    for(int i = 0; i < TAM; i++)
    {
        cout << " " << lista[i];
    }
}

//Busca em Arvore Binaria

/*void Insere_Arvore_Binaria(int valor)
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

void Busca_Seq(int chave)
{
    struct no *atual;
    atual = raiz;
    constante = 0;
    while(atual != NULL)
    {
        constante++;
        if(chave == atual -> dado)
        {
            cout << "\n Achou o valor " << chave << endl;
            cout << " Foram feitas " << constante << " operacoes" << endl;
            operacoes = operacoes + constante;
            return;
        }
        if(chave < atual -> dado)
        {
            atual = atual -> esq;
        }
        else
        {
            atual = atual -> dir;
        }
    }
    if(atual == NULL)
    {
        cout << "\n Nao achou o valor " << chave << endl;
        cout << " Foram feitas " << constante << " operacoes" << endl;
        operacoes = operacoes + constante;
    }
}*/

void Busca_Seq(int chave)
{
    int i;
    constante = 0;
    for(i = 0; i < TAM && i < chave; i++)
    {
        constante++;
        if(chave == lista[i])
        {
            cout << "\n Achei o valor " << chave << endl;
            cout << " Foram feitas " << constante << " operacoes" << endl;
            operacoes = operacoes + constante;
            return;
        }
    }
    cout << "\n Nao Achei " << chave << endl;
    cout << " Foram feitas " << constante << " operacoes" << endl;
    operacoes = operacoes + constante;
}

int partition(int p, int r)
{
    int aux, piv, i, j;
    piv = lista[p];
    i = p - 1;
    j = r + 1;
    while(true)
    {
        do
        {
            j = j - 1;
        }
        while(lista[j] > piv);
        do
        {
            i = i + 1;
        }
        while(lista[i] < piv);
        if(i < j)
        {
            aux = lista[i];
            lista[i] = lista[j];
            lista[j] = aux;
        }
        else
        {
            return j;
        }
    }
}

void QuickSort(int p, int r)
{
    int q;
    if(p < r)
    {
        q = partition(p, r);
        QuickSort(p, q);
        QuickSort(q + 1, r);
    }
}

void Repeticoes()
{
    for(int i = 0; i < rep; i++)
        Busca_Seq(rand());
}

void Gerar(int vet[TAM])
{
    for(int i = 0; i < TAM; i++)
        lista[i] = rand();
}

int main()
{
    int i;
    srand(time(NULL));
    vet = (int*)malloc(sizeof(int) * (TAM));
    Gerar(vet);
    QuickSort(0, TAM - 1);
    //for(i = 0; i < TAM; i++)
        //Insere_Arvore_Binaria(lista[i]);
    //Imprimir();
    Repeticoes();
    media_operacoes = operacoes / rep;
    cout << " \nA media das operacoes na Busca Sequencial eh: " << media_operacoes << " operacoes";
}
