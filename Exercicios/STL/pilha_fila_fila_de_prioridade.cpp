#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main()
{
    stack<int> pilha;
    queue<int> fila;
    priority_queue<int>fila_prioridade;

    pilha.push(10);
    pilha.push(100);
    pilha.push(50);
    pilha.push(20);

    fila.push(10);
    fila.push(100);
    fila.push(50);
    fila.push(20);

    fila_prioridade.push(10);
    fila_prioridade.push(100);
    fila_prioridade.push(50);
    fila_prioridade.push(20);

    cout << "Topo da Pilha " << pilha.top() << endl;
    cout << "Tamanha da Pilha " << pilha.size() << endl;
    cout << "\nFrente da Fila " << fila.front() << endl;
    cout << "Tamanho da Fila " << fila.size() << endl;
    cout << "\nFrente da Fila de Prioridade " << fila_prioridade.top() << endl;
    cout << "Tamanho da Fila de Prioridade " << fila_prioridade.size() << endl;

    pilha.pop();
    pilha.pop();
    fila.pop();
    fila.pop();
    fila_prioridade.pop();
    fila_prioridade.pop();

    cout << "\nTopo da Pilha depois do Pop " << pilha.top() << endl;
    cout << "Tamanho da Pilha depois do Pop " << pilha.size() << endl;
    cout << "\nFrente da Fila depois do Pop " << fila.front() << endl;
    cout << "Tamanho da Fila depois do Pop " << fila.size() << endl;
    cout << "\nFrente da Fila de Prioridade depois do Pop " << fila_prioridade.top() << endl;
    cout << "Tamanho da Fila de Prioridade depois do Pop " << fila_prioridade.size() << endl;

    pilha.pop();
    pilha.pop();
    fila.pop();
    fila.pop();
    fila_prioridade.pop();
    fila_prioridade.pop();

    cout << "\nTopo da Pilha depois do segundo Pop " << pilha.top() << endl;
    cout << "Tamanho da Pilha depois do segundo Pop " << pilha.size() << endl;
    cout << pilha.empty() << endl;
    cout << "\nFrente da Fila depois do segundo Pop " << fila.front() << endl;
    cout << "Tamanho da Fila depois do segundo Pop " << fila.size() << endl;
    cout << fila.empty() << endl;
    cout << "\nFrente da Fila de Prioridade depois do segundo Pop " << fila_prioridade.top() << endl;
    cout << "Tamanho da Fila de Prioridade depois do segundo Pop " << fila_prioridade.size() << endl;
    cout << fila.empty() << endl;
}
