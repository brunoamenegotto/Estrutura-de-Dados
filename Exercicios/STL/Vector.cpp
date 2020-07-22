#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    vector<int> lista;
    vector<int> :: iterator it;

    lista.push_back(40);
    lista.push_back(10);
    lista.push_back(30);
    lista.push_back(20);
    lista.push_back(50);

    it = lista.begin();
    it = it + 2;
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

    sort(lista.begin(), lista.end());

    for(it = lista.begin(); it != lista.end(); it++)
        cout << *it << " ";
    cout << endl;

    lista.erase(lista.begin());
    for(it = lista.begin(); it != lista.end(); it++)
        cout << *it << " ";
    cout << endl;

    lista.clear();
    if(lista.empty() == 1)
    {
        cout << "lista esta vazia";
    }
    else
    {
        cout << "lista ainda tem elemento";
    }
}
