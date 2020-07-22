#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> lista;

    lista.push_back(10);
    lista.push_back(15);
    lista.push_back(20);
    lista.push_back(25);
    lista.push_back(30);
    lista.push_back(35);
    lista.push_back(40);
    lista.push_back(45);

    for(int i = 0; i < lista.size(); i++)
    {
        cout << lista[i] << endl;
    }
}
