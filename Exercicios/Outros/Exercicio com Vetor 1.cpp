#include <iostream>
using namespace std;
const int TAM = 5;

int vetor[TAM];

int main ()
{
    int i;
    int maior, menor, soma;
    float media;

    for (i=0; i<TAM; i++)
        cin >> vetor[i];
        cout << endl;
        cout << "ordem do vetor: ";
        for (i=0; i<TAM; i++)
            cout << vetor[i] << " ";
            cout << endl;
            cout << "ordem inversa do vetor: ";
            for (i=TAM-1; i>=0; i--)
                cout << vetor[i] << " ";
                cout << endl;
                cout << "o maior valor do vetor eh: ";
            maior = 0;
            for (i=0; i<TAM; i++)
                if (vetor[i] > maior)
                    maior = vetor[i];
                    cout << maior << " ";
                    cout << endl;
                    cout << "o menor valor do vetor eh: ";
                menor = maior;
            for (i=0; i<TAM; i++)
                if (vetor[i] < menor)
                    menor = vetor[i];
                    cout << menor << " ";
                    cout << endl;
            soma = 0;
            media = 0;
            cout << "a media do vetor eh: ";
            for (i=0; i<TAM; i++)
                soma = soma + vetor[i];
                media = soma/TAM;
                cout << media << " ";
    return 0;
}
