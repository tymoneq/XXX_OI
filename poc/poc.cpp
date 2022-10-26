#include <bits/stdc++.h>
// Tymon Tumialis
using namespace std;

int main()
{
    // dodaj binary searcha po pierszym zbiorze
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> Bajtek(n);
    vector<int> Bitek(m);
    // vector<pair<vector<poz>, vector<pair<int, int>>>> train(k + 1); // first = Bajtek second = Bitek

    vector<bool> visited(n);
    vector<int> distance_front(n);
    vector<int> distance_back(n);
    // wczytanie danych
    for (int i = 0; i < n; i++)
        cin >> Bajtek[i];
    for (int i = 0; i < m; i++)
        cin >> Bitek[i];

    int index = 0;
    // liczenie dystansu
    for (int i = 0; i < n; i++)
    {
        distance_front[i] = index;
        if (Bajtek[i] == Bitek[index] && index < Bitek.size())
            index++;
    }
    index = 0;
    int u = m - 1;
    for (int i = n - 1; i >= 0; i--)
    {
        distance_back[i] = index;
        if (Bajtek[i] == Bitek[u] && u >= 0)
        {
            index++;
            u--;
        }
    }
    // binary search
    // wczytanie do wektora

    for (auto el : visited)
        cout << el << " ";
    return 0;
}