#include <bits/stdc++.h>

using namespace std;
int main(int argc, char ** argv)
{
    ifstream plik, plik_2;
    string test, test_2;

    
    test_2 = "wynik.txt";
    test = argv[1];
    plik.open(test);
    plik_2.open(test_2);
    int a, b, counter = 1;
    bool error = false;
    while (plik >> a && plik_2 >> b)
    {
        if (!(a == b))
        {
            cout << "Error in line " << counter << "\n";
            error = true;
        }
        counter += 1;
    }
    if (!error)
        cout << "1000%\n";

    return 0;
}