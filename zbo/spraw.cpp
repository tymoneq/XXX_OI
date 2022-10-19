#include <bits/stdc++.h>

using namespace std;
int main()
{
    ifstream plik, plik_2;
    string test, test_2;
    cout << " Podaj numer testu: ";
    cin >> test;
    cout << "\n Podaj nazwę swojego wyjścia: ";
    cin >> test_2;
    test += ".out";
    plik.open(test);
    plik_2.open(test_2);
    int a, b;
    while (plik >> a && plik_2 >> b)
    {
        if (!(a == b))
        {
            cout << "Error in line " << a;
        }
    }

    return 0;
}