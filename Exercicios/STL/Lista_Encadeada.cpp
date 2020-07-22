#include<list>
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    list<int> lista;
    list<int> :: iterator it;

    lista.push_back(40);
    lista.push_back(10);
    lista.push_back(30);
    lista.push_back(20);
    lista.push_back(50);

    it = lista.begin();
    it++; it++;
    lista.insert(it, 15);

    for(it = lista.begin(); it != lista.end(); it++)
        cout << *it << " ";
    cout << endl;

    it = (find(lista.begin(), lista.end(), 40));
    if(it != lista.end())
    {
        cout << "encontrei\n";
    }
    else
    {
        cout << "nao encontrei\n";
    }

    lista.sort();
    for(it = lista.begin(); it != lista.end(); it++)
        cout << *it << " ";
    cout << endl;

    lista.pop_front();
    for(it = lista.begin(); it != lista.end(); it++)
        cout << *it << " ";
    cout << endl;

    lista.remove(15);
    for(it = lista.begin(); it != lista.end(); it++)
        cout << *it << " ";
    cout << endl;

    lista.clear();
    if(lista.empty())
    {
        cout << "lista vazia";
    }
}
