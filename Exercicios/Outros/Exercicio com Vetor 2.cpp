#include<iostream>
using namespace std;
const int TAM = 5;

int vetorA [TAM];
int vetorB [TAM];
int aux [TAM];
int main ()
{
    int i;

    for (i=0; i<TAM; i++)
        cin >> vetorA[i];
        cout << endl;
        cout << "vetor A: ";
        for (i=0; i<TAM; i++)
            cout << vetorA[i] << " ";
        cout << endl;
        cout << "vetor B: ";
        for (i=TAM-1; i>=0;i--)
            cout << vetorA[i] << " ";
        cout << endl;

        for (i=0; i<=TAM; i++)
            aux[i] = vetorA[i];
            vetorA[i] = vetorB[i];
            vetorB[i] = aux[i];
            cout << vetorB[i] << " ";
    return 0;
    system("pause");

}
