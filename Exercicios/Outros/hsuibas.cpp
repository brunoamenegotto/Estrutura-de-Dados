#include<cstdlib>
#include<ctime>
#include <iostream>
#include<stdlib.h>
using namespace std;
const int TAM = 40000;

int A[TAM];

void bubble()
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
void Gerar()
{
    for (int i = 0; i < TAM; i++)
        A[i] = rand();
}

void Imprimir()
{
    for(int i = 0; i < TAM; i++)
    {
        cout << " " << A[i];
    }
}
int main()
{
    clock_t temp1, temp2;
    Gerar();
    temp1 = clock();
    bubble();
    temp2 = clock() - temp1;
    cout << "Tempo eh: " << (float) temp2/CLOCKS_PER_SEC << endl;
    Imprimir();
    system("pause");
}
