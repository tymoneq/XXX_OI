#include <bits/stdc++.h>
// Tymon Tumialis
using namespace std;

struct poz
{
    int front = 0;
    int back = 0;
    int index = 0;
};
inline bool first_less_front(poz lhs, int rhs) { return lhs.front < rhs; }
inline bool first_less_end(poz lhs, int rhs) { return lhs.front <= rhs; }
inline bool first_greater_back(poz lhs, int rhs) { return lhs.back < rhs; }
inline bool first_greater_back_end(poz lhs, int rhs) { return lhs.back > rhs; }

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> Bajtek(n);
    vector<int> Bitek(m);
    vector<pair<vector<poz>, vector<pair<int, int>>>> train(k + 1); // first = Bajtek second = Bitek
    vector<bool> visited(n, 0);
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

            
            auto itr_begin_start = lower_bound(train[i].first.begin(), train[i].first.end(), Bit.first, first_less_front);
            auto itr_begin_end = lower_bound(train[i].first.rbegin(), train[i].first.rend(), Bit.first, first_less_end);
            auto itr_back_start = lower_bound(train[i].first.begin(), train[i].first.end(), Bit.second, first_greater_back);
            auto itr_back_end = lower_bound(train[i].first.rbegin(), train[i].first.rend(), Bit.second, first_greater_back_end);
            //cout << "<1> " << itr_begin_end->index << endl;
            //cout << "<2> " << itr_back_end->index << endl;
            //--itr_begin_end;
            ++itr_back_end;
            //cout << "<3>" << itr_begin_end->index << endl;
            //cout << "<4>" << itr_back_end->index << endl;
            
            // int index_begin_f = itr_begin_start->index;
            // int index_begin_b = itr_begin_end->index;
            // // #################
            // int index_back_f = itr_back_start->index;
            // int index_back_end = itr_back_end->index;
            int pocz_zakres = max(itr_begin_start->index, itr_back_start->index);
            int kon_zakres = min(itr_back_end->index, itr_begin_end->index);
            for (int j = pocz_zakres; j <= kon_zakres; j++)
                if (Bajtek[j] == i)
                    visited[j] = 1;
        }
    }
    for (auto el : visited)
        cout << el << " ";
    return 0;
}