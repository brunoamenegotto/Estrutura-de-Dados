#include<iostream>
using namespace std;
const int TAM = 5;

int vetorA [TAM];
int vetorB [TAM];

int main ()
{
    int i, numero;

    cout << "Digite um numero: ";
    cin >> numero;

    for (i=0; i<TAM; i++)
        cin >> vetorA[i];
        cout << endl;
        cout << "vetor A: ";
        for (i=0; i<TAM; i++)
            cout << vetorA[i] << " ";
        cout << endl;
        cout << "vetor B: ";
        for (i=0; i<TAM; i++)
            if (vetorA[i] > numero)
                vetorB[i] = vetorA[i];
                for (i=0; i<TAM; i++)
                    cout << vetorB[i] << " ";
    return 0;
}
