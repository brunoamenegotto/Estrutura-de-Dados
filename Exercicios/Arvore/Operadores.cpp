#include <iostream>
#include <stdlib.h>
using namespace std;

const int OPERANDO = 1;
const int OPERADOR = 2;

struct no
{
    int tipo;
    union
    {
        char operador;
        int operando;
    };
    struct no *esq;
    struct no *dir;
};

struct no *raiz = NULL;

struct no *cria_operando(int valor)
{
    struct no *aux;
    aux = new(struct no);
    aux -> tipo = OPERANDO;
    aux -> operando = valor;
    aux -> esq = NULL;
    aux -> dir = NULL;
    return aux;
};

struct no *cria_equacao(char opera, struct no *esq, struct no *dir)
{
    struct no *aux = new(struct no);
    aux -> tipo = OPERADOR;
    aux -> operador = opera;
    aux -> esq = esq;
    aux -> dir = dir;
    return aux;
};

void em_ordem(struct no *atual)
{
    if(atual != NULL)
    {
        em_ordem(atual -> esq);
        if(atual -> tipo == OPERANDO)
            cout << atual -> operando;
        else
            cout << atual -> operador;
        em_ordem(atual -> dir);
    }
}

void pre_ordem(struct no *atual)
{
    if(atual != NULL)
    {
        if(atual -> tipo == OPERANDO)
            cout << atual -> operando;
        else
            cout << atual -> operador;
        pre_ordem(atual -> esq);
        pre_ordem(atual -> dir);
    }
}

void pos_ordem(struct no *atual)
{
    if(atual != NULL)
    {
        pre_ordem(atual -> esq);
        pre_ordem(atual -> dir);
        if(atual -> tipo == OPERANDO)
            cout << atual -> operando;
        else
            cout << atual -> operador;
    }
}

int opera(char opera, int a, int b)
{
    switch(opera)
    {
        case '*':
            return a * b;
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '/':
            return a / b;
    }
}


int resolve(struct no *atual)
{
    int operando1, operando2, resultado;
    if (atual -> tipo == OPERADOR)
    {
        operando1 = resolve(atual -> esq);
        operando2 = resolve(atual -> dir);
        resultado = opera(atual -> operador, operando1, operando2);
        return resultado;
    }
    else return atual -> operando;
}

int main ()
{
    struct no *aux1;
    struct no *aux2;
    struct no *aux3;

    aux1 = cria_operando(3);
    aux2 = cria_operando(2);
    aux3 = cria_equacao('*', aux1, aux2);

    em_ordem(aux3);
    cout << "\n";
    cout << resolve(aux3);
    cout << "\n";
    pre_ordem(aux3);
    cout << "\n";
    cout << resolve(aux3);
    cout << "\n";
    pos_ordem(aux3);
    cout << "\n";
    cout << resolve(aux3);
    system("pause");
}
