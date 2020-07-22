#include<iostream>
using namespace std;
const int TAM = 10;

int lista[TAM];
int comprimento = 0;

void inserelista(int valor)
{
    int i, maior;
    if (comprimento == TAM)
    {
        cout << "\nLista Cheia";
        return;
    }
    for (i = comprimento; i > 0 && valor < lista[i-1]; i--)
    {
        lista[i] = lista[i-1];
    }
    lista[i] = valor;
    comprimento ++;    
    cout << "\nValor " << valor << " inserido";    
}
void removeValor(int valor)
{
    int i, j;
    for(i = 0; i < comprimento; i++)
    {
        if(valor == lista[i])
        {
            for(j = i; j < comprimento -1; j++)
                lista[j] = lista[j+1];
                cout << "\nRemovido o valor " << valor;
                comprimento --;
                return;
        }
    }
    cout << "\nValor nao encontrado";
}
void removeLista(int posicao)
{
    int i, j;
    for(i = 0; i < comprimento; i++)
    {
        if (posicao == i)
        {
            for(j = i; j < comprimento -1; j++)
                lista[j] = lista[j+1];
                cout << "\nRemovido o valor da " << posicao+1 << " posicao";
                comprimento --;
                return;
        }
    }
    cout << "\nPosicao " << posicao << " nao encontrado";
}
void recuperaLista(int posicao)
{
    if (posicao < 0 || posicao > comprimento)
    {
        cout << "\nPosicao " << posicao << " Invalida";
        return;
    }
    cout << "\nElemento na posicao " << posicao << " foi recuperado seu valor eh " << lista[posicao];
}
void imprimir()
{
    int i;
    if (comprimento == 0)
    {
        cout << "\nLista Vazia";
        return;
    }
    cout << "\n";
    for(i = 0; i < comprimento; i++)
        cout << lista[i] << " ";
}

void maiorValor(int lista[])
{
    int maior;
    maior = lista[0];
    for(int i = 1; i < comprimento; i++)
    {
        if(maior < lista[i])
        {
            maior = lista[i];
        }
    }
    cout << "O maior valor eh " << maior;
}

void removeValores(int lista[])
{
    for(int i = 0; i < comprimento; i++)
    {
        lista[i] = 0;
    }
    comprimento = 0;
    cout << "\nTodos os valores foram removidos";
}

int main()
{
    inserelista(2);
    inserelista(5);
    inserelista(11);
    inserelista(9);
    inserelista(10);    
    imprimir();
    removeValores(lista);
    imprimir();
    
    
    /*removeValor(9);
    removeValor(2);
    inserelista(1);
    imprimir();
    removeLista(0);
    imprimir();
    recuperaLista(0);
    imprimir();*/
    //maiorValor(lista);
}
