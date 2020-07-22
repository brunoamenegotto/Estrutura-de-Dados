#include<iostream>
#include<stdio.h>

using namespace std;

const int TAM = 10;
int chave, tabela[TAM], i, pos;
int cont = 0;

void gerarTabela()
{
    for(i = 0; i < TAM; i++)
    {
        tabela[i] = -1;
    }
}

int espalha(int chave)
{
    return chave % TAM;
}
int reespalha(int pos)
{
    return (pos +1) % TAM;

}
void insere(int chave)
{
    if(cont == TAM)
    {
        cout << " Tabela cheia elemento " << chave << " nao pode ser inserido" << endl;
        return;
    }
    pos = espalha(chave);
    if(tabela[pos] == chave)
    {
        cout << " Elemento " << chave << " repetido" << endl;
        return;
    }
    if(tabela[pos] != -1)
    {
        while(tabela[pos] != -1)
        {
            pos = reespalha(pos);
            if(tabela[pos] == chave)
            {
                cout << " Elemento " << chave << " repetido" << endl;
                return;
            }
        }
    }
    tabela[pos] = chave;
    cont ++;
    cout << " Elemento: " << chave << " inserido com sucesso" << endl;
}

void busca(int chave)
{
    int cont2 = 0;
    pos = espalha(chave);
    if(tabela[pos] != -1)
    {
        while(tabela[pos] != -1)
        {
            if(tabela[pos] == chave)
            {
                cout << " Elemento: " << chave << " encontrado" << endl;
                return;
            }
            else if(cont2 == TAM)
            {
                cout << " Elemento: " << chave << " nao encontrado" << endl;
                return;
            }
            pos = reespalha(pos);
            cont2 ++;
        }
    }
}

void imprimir()
{
    for (i = 0; i < TAM; i++)
    {
        cout << " Chave [" << i << "] = " << tabela[i] << " " << endl;
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
