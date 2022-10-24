#include <bits/stdc++.h>
// Tymon Tumialis
using namespace std;

// struct poz
// {
//     int front = 0;
//     int back = 0;
//     int index = 0;
// };

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> Bajtek(n);
    vector<int> Bitek(m);
    // vector<pair<vector<poz>, vector<pair<int, int>>>> train(k + 1); // first = Bajtek second = Bitek
    vector<vector<pair<int, int>>> Baj_front(k + 1);
    vector<vector<pair<int, int>>> Baj_back(k + 1);
    vector<vector<pair<int, int>>> Bit_front(k + 1);
    vector<bool> visited(n);
    vector<int> distance_front(n);
    vector<int> distance_back(n);
    // wczytanie danych
    for (int i = 0; i < n; i++)
        cin >> Bajtek[i];
    for (int i = 0; i < m; i++)
        cin >> Bitek[i];

    int u = 1;
    // liczenie dystansu
    for (int i = 1; i < n; i++)
    {
        if (Bajtek[i] == Bitek[u])
        {
            distance_front[i] = distance_front[i - 1] + 1;
            u += 1;
        }
        else
            distance_front[i] = distance_front[i - 1];
    }
    u = m - 1;

    for (int i = n - 1; i >= 0; i--)
    {
        if (Bajtek[i] == Bitek[u])
        {
            if (i == n - 1)
                distance_back[i] = 0;
            else
                distance_back[i] = distance_back[i + 1] + 1;
            u -= 1;
        }
        else
            distance_back[i] = distance_back[i + 1];
    }
    // wczytanie do wektora
    for (int i = 0; i < n; i++)
    {
        int val = Bajtek[i];
        Baj_front[val].push_back(make_pair(distance_front[i], i));
        Baj_back[val].push_back(make_pair(distance_back[i], i));
    }
    for (int i = 0; i < m; i++)
    {
        auto par = make_pair(i, m - i - 1);
        int val = Bitek[i];
        Bit_front[val].push_back(par);
    }
    // obliczanie które mógł zapisać

    for (int i = 1; i <= k; i++)
    {
        for (auto Bit : Bit_front[k])
        {
            
            Bit.first;
            Bit.second;
            auto itr_begin = lower_bound(Baj_front[k].begin(), Baj_front[k].begin(), Bit);
        }
    }
    for (auto el : visited)
        cout << el << " ";
    return 0;
}