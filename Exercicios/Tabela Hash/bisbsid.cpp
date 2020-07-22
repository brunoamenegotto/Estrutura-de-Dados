#include<iostream>
using namespace std;

const int TAM = 10;
int tabela[TAM], cont = 0;

void geratabela()
{
    for(int i = 0; i < TAM; i++)
    {
        tabela[i] = -1;
    }
}

int espalha(int chave)
{
    return chave%TAM;
}

int reespalha(int pos)
{
    return ((pos + 1)%TAM);
}

void insere(int chave)
{
    int pos = espalha(chave);
    if(cont == TAM)
    {
        cout<<"tabela cheia!"<<endl;
        return;
    }
    if(tabela[pos] == -1)
    {
        tabela[pos] = chave;
        cont++;
        return;
    }
    else
    {
        while(tabela[pos] != -1)
        {
            pos = reespalha(pos);
            if(tabela[pos] == -1)
            {
                tabela[pos] = chave;
                cont++;
                return;
            }
        }
    }
}

void busca(int chave)
{
    int cont2 = 0;
    int pos = espalha(chave);
    if(cont == 0)
    {
        cout<<"Tabela vazia!"<<endl;
        return;
    }
    if(tabela[pos] == -1)
    {
        cout<<"Nao achou "<<chave<<endl;
        return;
   }
	else{
        while(tabela[pos] != -1)
        {
            if(tabela[pos] == chave)
            {
                cout<<"Achei "<<chave<<endl;
                return;
            }
            else if(cont2 == TAM)
            {
                cout<< "Nao achei\n";
                return;
            }
        pos = reespalha(pos);
        cont2++;
        }
    }

}

void imprime()
{
    for(int i = 0; i < TAM; i++)
    {
        cout<<tabela[i]<<' ';
    }
    cout<<endl;
}

int main()
{
    geratabela();
    insere(119);
    insere(21);
    insere(32);
    insere(3);
    insere(252);
    insere(29);
    insere(38);
    insere(222);
    insere(379);
    insere(0);
    insere(95);
    imprime();
    busca(32);
    busca(26);
    busca(2);
}
