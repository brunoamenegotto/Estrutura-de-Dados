#include<iostream>
#include<cstdio>
#include<cstring>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct no
{
    char palavra[40];
    int contador;
    struct no *esq;
    struct no *dir;
};
struct no *raiz = NULL;

void insererept(char valor[])
{
    struct no *atual;
    struct no *anterior;
    struct no *novo;

    novo = new(struct no);
    strcpy(novo -> palavra, valor);
    novo -> esq = NULL;
    novo -> dir = NULL;
    novo -> contador = 1;
    if(raiz == NULL)
    {
        raiz = novo;
        return;
    }
    atual = raiz;
    while(atual != NULL)
    {
        anterior = atual;
        if(strcmp(valor, atual -> palavra) == 0)
        {
            novo -> contador ++;
            return;
        }
        if(strcmp(valor, atual -> palavra) < 0)
        {
            atual = atual -> esq;
        }
        else
        {
            atual = atual -> dir;
        }
    }
    if(strcmp(valor, anterior -> palavra) < 0)
    {
        anterior -> esq = novo;
    }
    else
    {
        anterior -> dir = novo;
    }
}

void em_ordem(struct no *atual)
{
    if(atual != NULL)
    {
        em_ordem(atual -> esq);
        cout << " Palavra: " << atual -> palavra << " Contador: " << atual -> contador <<  "\n";
        em_ordem(atual -> dir);
    }
}

int main ()
{
    FILE *fp;
    char palavra[40];

    fp = fopen("texto.txt", "r");

    if(fp == NULL)
    {
        cout << "\n Nao achou o arquivo";
        return 0;
    }
    while(!feof(fp))
    {
        fscanf(fp, "%s", palavra);
        insererept(palavra);
    }
    em_ordem(raiz);
    fclose(fp);
    system ("pause");
}
