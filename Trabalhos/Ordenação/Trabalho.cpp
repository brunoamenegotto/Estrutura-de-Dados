#include<cstdlib>
#include<ctime>
#include<iostream>
#include<stdio.h>

using namespace std;

const int TAM = 5000;
int A[TAM];
int *vet;
int TamHeap;

int partition(int p, int r)
{
    int aux, piv, i, j;
    piv = A[p];
    i = p - 1;
    j = r + 1;
    while(true)
    {
        do
        {
            j = j - 1;
        }
        while(A[j] > piv);
        do
        {
            i = i + 1;
        }
        while(A[i] < piv);
        if(i < j)
        {
            aux = A[i];
            A[i] = A[j];
            A[j] = aux;
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
        q=partition(p, r);
        QuickSort(p, q);
        QuickSort(q + 1, r);
    }
}

void MergeSort(int A[TAM], int inicio, int fim)
{
    int i, j, k, meio,*aux;
    if(inicio == fim)
    {
        return;
    }
    meio = (inicio + fim)/2;
    MergeSort(A, inicio, meio);
    MergeSort(A, meio + 1, fim);

    i = inicio;
    j = meio + 1;
    k = 0;
    aux = (int*)malloc(sizeof(int) * (fim - inicio + 1));
    while(i < meio + 1 || j < fim + 1)
    {
        if(i == meio + 1)
        {
            aux[k] = A[j];
            j++;
            k++;
        }
        else if(j == fim + 1)
        {
            aux[k] = A[i];
            k++;
            i++;
        }
        else if(A[i] < A[j])
        {
            aux[k] = A[i];
            i++;
            k++;
        }
        else
        {
            aux[k] = A[j];
            i++;
            k++;
        }
    }
    for(i = inicio; i <= fim; i++)
    {
        A[i] = aux[i - inicio];
    }
    free(aux);
    return;
}

void Heapify(int i)
{
    int l, r, maximo, aux;
    l = 2 * i + 1;
    r = 2 * i + 2;

    if(l < TamHeap && A[l] > A[i])
    {
        maximo = l;
    }
    else
    {
        maximo = i;
    }
    if(r < TamHeap && A[r] > A[maximo])
    {
        maximo = r;
    }
    if(maximo != i)
    {
        aux = A[i];
        A[i] = A[maximo];
        A[maximo] = aux;
        Heapify(maximo);
    }

}

void ConstroiHeap()
{
    int j;
    TamHeap = TAM;
    for(j = (TAM/2) - 1; j >= 0; j--)
    {
        Heapify(j);
    }
}

void HeapSort()
{
    int k, aux;
    ConstroiHeap();
    for(k = TAM - 1; k >= 1; k--)
    {
        aux = A[0];
        A[0] = A[k];
        A[k] = aux;
        TamHeap = TamHeap - 1;
        Heapify(0);
    }
}

void SelectionSort()
{
    int atual, aux;
    for(int i = 0; i <= TAM - 2; i++)
        {
        atual = i;
        for(int k = i + 1;k <= TAM - 1; k++)
        {
            if(A[atual] > A[k])
            {
                atual = k;
            }
        }
        aux = A[i];
        A[i] = A[atual];
        A[atual] = aux;
    }
}

void InsertionSort()
{
    bool achou;
    int x, i, aux;
    for(int k = 1; k <= TAM - 1; k++)
    {
        x = A[k];
        i = k - 1;
        achou = false;
        while(!achou && i >= 0)
        {
            if(A[i] > x)
            {
                aux = A[i];
                A[i] = A[i + 1];
                A[i + 1] = aux;
                i = i - 1;
            }
            else
                achou = true;
        }
    }
}

void BubbleSort()
{
    int aux[TAM];
    int pass;
    pass = 1;
    bool sorted;
    sorted = false;
    while (!sorted && (pass < TAM))
    {
        sorted = true;
        for (int i = 0; i<=TAM-pass-1; i++)
        {
            if (A[i] > A[i+1])
            {
                aux[i] = A[i];
                A[i] = A[i + 1];
                A[i + 1] = aux[i];
                sorted = false;
            }
        }
        pass = pass + 1;
    }
}

void GerarM(int vet[TAM])
{
    for (int i = 0; i < TAM; i++)
        A[i] = rand();
}

void Gerar()
{
    for(int i = 0; i < TAM; i++)
        A[i] = rand();
}

void Imprimir()
{
    for(int i = 0;i < TAM; i++)
    {
        cout << " " << A[i];
    }
}

int main()
{
    clock_t tempo1, tempo2;
    Gerar();
    tempo1 = clock();
    QuickSort(0, TAM - 1);
    tempo2 = clock() - tempo1;
    //Imprimir();
    cout << endl;
    cout << " QuickSort Tempo eh: " << (float)tempo2/CLOCKS_PER_SEC << endl;

    vet = (int*)malloc(sizeof(int) * (TAM));
    GerarM(vet);
    tempo1 = clock();
    MergeSort(A, 0, TAM);
    tempo2 = clock() - tempo1;
    //Imprimir();
    cout << endl;
    cout << " MergeSort Tempo eh: " << (float) tempo2/CLOCKS_PER_SEC << endl;

    Gerar();
    tempo1 = clock();
    HeapSort();
    tempo2 = clock() - tempo1;
    //Imprimir();
    cout << endl;
    cout << " HeapSort Tempo eh: " << (float) tempo2/CLOCKS_PER_SEC << endl;

    Gerar();
    tempo1 = clock();
    SelectionSort();
    tempo2 = clock() - tempo1;
    //Imprimir();
    cout << endl;
    cout << " SelectionSort Tempo eh: " << (float)tempo2/CLOCKS_PER_SEC << endl;

    Gerar();
    tempo1 = clock();
    InsertionSort();
    tempo2 = clock() - tempo1;
    //Imprimir();
    cout << endl;
    cout << " InsertionSort Tempo eh: " << (float)tempo2/CLOCKS_PER_SEC << endl;

    Gerar();
    tempo1 = clock();
    BubbleSort();
    tempo2 = clock() - tempo1;
    //Imprimir();
    cout << endl;
    cout << " BublleSort Tempo eh: " << (float) tempo2/CLOCKS_PER_SEC << endl;
    system("pause");
}
