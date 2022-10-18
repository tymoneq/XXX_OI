#include <bits/stdc++.h>
// Tymon Tumialis
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string znaki;
    int n, H, wynik = 0, stopien_baz = 0, otwarte = 0;
    cin >> n >> H;
    cin >> znaki;
    if (H == 1)
    {
        cout << n / 2 << "\n";
    }
    else
    {
        // liczenie stopnia bazowego
        for (int i = 0; i < n; i++)
        {
            if (znaki[i] == '(')
                otwarte += 1;
            else if (znaki[i] == ')')
            {
                stopien_baz = max(stopien_baz, otwarte);
                --otwarte;
            }
        }
        wynik = (H - stopien_baz) * 2;
        cout << abs(wynik) << "\n";
    }

    return 0;
}