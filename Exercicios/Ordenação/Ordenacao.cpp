#include<cstdlib>
#include<ctime>
#include <iostream>
#include<stdlib.h>
using namespace std;
const int TAM = 1000;

int A[TAM];

int bubble ( )
{
    int aux;
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
                aux = A[i];
                A[i] = A[i + 1];
                A[i] = aux;
                sorted = false;
            }
            pass = pass + 1;
        }
    }
}
void gera()
{
    for (int i = 0; i < TAM; i++)
        A[i] = rand();
}

int main()
{
    clock_t temp1, temp2;
    gera();
    temp1 = clock();
    bubble();
    temp2 = clock() - temp1;
    cout << "Tempo eh " << (float) temp2/CLOCKS_PER_SEC << endl;
    system("pause");
}
