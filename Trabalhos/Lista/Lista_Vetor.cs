using System;

class Lista_Vetor
{
    const int TAM = 10;
    int[] lista = new int[TAM];
    int comprimento = 0;

    void insereLista(int valor)
    {
        int i;
        if(comprimento == TAM)
        {
            Console.WriteLine("Lista Cheia");
            return;
        }
        for(i = comprimento; i > 0 && valor < lista[i-1]; i++)
            lista[i] = lista[i-1];
            lista[i] = valor;
            comprimento++;
            Console.WriteLine("Valor {0} ", valor, " inserido com sucesso");
    }
    static void Main()
    {
        insereLista(2);
        insereLista(5);
        insereLista(11);
        insereLista(9);
        insereLista(10);
        insereLista(15);
    }
}