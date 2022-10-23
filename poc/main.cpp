#include <bits/stdc++.h>
// Tymon Tumialis
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> Bajtek(n);
    vector<int> Bitek(m);
    vector<pair<vector<pair<int, int>>, vector<pair<int, int>>>> train(k + 1); // first = Bajtek second = Bitek
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
        auto par = make_pair(distance_front[i], distance_back[i]);
        int val = Bajtek[i];
        train[val].first.push_back(par);
    }
    for (int i = 0; i < m; i++)
    {
        auto par = make_pair(i, m - i-1);
        int val = Bitek[i];
        train[val].second.push_back(par);
    }
    int l=0;
    return 0;
}