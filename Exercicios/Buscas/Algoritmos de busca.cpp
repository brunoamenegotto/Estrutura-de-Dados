#include<iostream>
using namespace std;

const int TAM=10;
int vetor[TAM], n, contSeq, contBin, contSen;

void geraVetor()
{
    for(int i = 0 ; i < TAM ; i++)
    {
        //cout<<"Informe um numero para colocar no vetor: ";
        vetor[i]=i;
        n++;
        cout<<vetor[i]<<' ';
    }
}

void buscaBinaria(int valor)
{
    int inicio=0;
    int fim=TAM-1;
    int meio;
    while(inicio <= fim)
    {
        meio=(inicio+fim)/2;
        contBin++;
        if(vetor[meio]==valor)
        {
            cout<<"Achou!";
            return;
        }
        if(vetor[inicio] == valor)
        {
            cout<<"Achou!!";
            return;
        }
        if(vetor[fim] == valor)
        {
            cout<<"Achou!!!";
            return;
        }
        if(vetor[meio] > valor)
        {
            fim = meio - 1;
        }
        else
        {
            inicio = meio + 1;
        }
    }
    cout<<"Nao achei!!!"<<endl;
}

void buscaSentinela(int chave)
{
   int i, n;
   n = TAM;
   vetor[n - 1] = chave;
   for (i = 0; vetor[i] < chave; i++) ;
   if (i == n || vetor[i] != chave)
    {
        cout << "Elemento encontrado";
        contSen++;
        return;
    }
    else
    {
        cout <<"Elemento nao encontrado";
        contSen++;
    }
}

void buscaSequencial(int chave)
{
    int i;
    for(i=0 ; i<n && vetor[i]<=chave ; i++)
    {
        contSeq++;
        if(vetor[i] == chave)
        {
            cout<<"Achei"<<endl;
            return;
        }
    }
    cout<<"Nao achei"<<endl;
}

int main()
{
    geraVetor();
    //buscaBinaria(6);
    buscaSequencial(6);
    buscaSentinela(6);
    cout<<"Contagens de repeticoes: "<<contSeq<<endl;
    cout<<"Contagens de repeticoes: "<<contSen<<endl;
}
