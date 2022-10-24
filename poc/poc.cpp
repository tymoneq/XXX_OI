#include <bits/stdc++.h>
// Tymon Tumialis
using namespace std;

struct poz
{
    int front = 0;
    int back = 0;
    int index = 0;
};
inline bool first_less(poz lhs, int rhs) { return lhs.front < rhs; }
inline bool first_greater(poz lhs, int rhs) { return lhs.back > rhs; }
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> Bajtek(n);
    vector<int> Bitek(m);
    vector<pair<vector<poz>, vector<pair<int, int>>>> train(k + 1); // first = Bajtek second = Bitek
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
        poz pos;
        pos.front = distance_front[i];
        pos.back = distance_back[i];
        pos.index = i;
        train[val].first.push_back(pos);
    }
    for (int i = 0; i < m; i++)
    {

        auto par = make_pair(i, m - i - 1);
        int val = Bitek[i];
        train[val].second.push_back(par);
    }
    // obliczanie które mógł zapisać

    for (int i = 1; i <= k; i++)
    {
        for (auto Bit : train[i].second)
        {

            Bit.second;
            auto itr_begin = lower_bound(train[i].first.begin(), train[i].first.end(), Bit.first, first_less);
            auto itr_back = lower_bound(train[i].first.rbegin(), train[i].first.rend(), Bit.second, first_greater);
            int index_f = itr_begin->index;
            int index_b = itr_back->index;
            for (int j = index_f; j <= index_b; j++)
                if (Bajtek[j] == i)
                    visited[j] = 1;
        }
    }
    for (auto el : visited)
        cout << el << " ";
    return 0;
}