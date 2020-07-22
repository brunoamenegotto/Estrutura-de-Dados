#include <iostream>

using namespace std;
const int TAM = 10;

struct no
{
    int dado;
    struct no *prox;
};

struct no *tabela[TAM];

void gerarTabela()
{
    for(int i = 0; i < TAM; i++)
    {
        tabela[i] = NULL;
    }
}

int espalha(int chave)
{
    return chave % TAM;
}

void insere(int chave)
{
    struct no *novo, *atual, *anterior;
    int pos;

    pos = espalha(chave);
    atual = tabela[pos];

    while(atual != NULL)
    {
        if(atual -> dado == chave)
        {
            cout<<" Elemento " << chave << " repetido" << endl;
            return;
        }
        anterior = atual;
        atual = atual -> prox;
    }

    novo = new(struct no);
    novo -> dado = chave;
    novo -> prox = NULL;

    if(tabela[pos] == NULL)
    {
        tabela[pos] = novo;
    }
    else
    {
        anterior -> prox = novo;
    }
    cout << " Elemento " << chave << " inserido com sucesso " << endl;
}

void busca(int chave)
{
    struct no *atual;
    int pos;

    pos = espalha(chave);
    atual = tabela[pos];

    while(atual != NULL)
    {
        if(atual -> dado == chave)
        {
            cout << " Elemento " << chave << " encontrado" << endl;
            return;
        }
        atual = atual -> prox;
    }
    cout << " Elemento " << chave << " nao encontrado" << endl;
}

void imprimir()
{
    struct no *atual;

    for(int i = 0; i < TAM; i++)
    {
        atual = tabela[i];

        cout << " Chave [" << i << "] = ";
        while(atual != NULL)
        {
            cout << atual -> dado << " ";
            atual = atual -> prox;
        }
        cout << endl;
    }
}

int main()
{
    gerarTabela();
    insere(5);
    insere(15);
    insere(2);
    insere(6);
    insere(12);
    insere(13);
    insere(14);
    insere(25);
    insere(22);
    insere(20);
    insere(15);
    insere(33);
    insere(30);
    imprimir();
    busca(25);
    busca(16);
    busca(2);
    busca(13);
}
