#include <bits/stdc++.h>
// Tymon Tumialis
using namespace std;
void binary_b(int search, vector<int> &zbior, int l, int r, int &index)
{
    int zakres = (r - l) / 2;
    int val = zbior[zakres];


    if (r == l && zbior.size() > 1)
    {
        index = l;
        return;
    }
    else if (r == l && zbior.size() == 1)
    {
        if (search >= val)
        {
            index = 0;
            return;
        }
        else
        {
            index = 2;
            return;
        }
    }

    if (search == val)
    {
        index = zakres;
        return;
    }

    else if (search > val)
    {
        r = zakres;
        binary_b(search, zbior, l, r, index);
    }
    else if (search < val)
    {
        l = zakres;
        binary_b(search, zbior, l, r, index);
    }
}

void binary_f(int search, vector<int> &zbior, int l, int r, int &index)
{
    int zakres = (r - l) / 2;
    int val = zbior[zakres];
    if (r == l && zbior.size() > 1)
    {
        index = l;
        return;
    }
    else if (r == l && zbior.size() == 1)
    {
        if (search <= val)
        {
            index = 0;
            return;
        }
        else
        {
            index = 2;
            return;
        }
    }

    if (search == val)
    {
        index = zakres;
        return;
    }

    else if (search < val)
    {
        l = zakres;
        binary_f(search, zbior, l, r, index);
    }
    else if (search > val)
    {
        r = zakres;
        binary_f(search, zbior, l, r, index);
    }
}
int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> Bajtek(n);
    vector<int> Bitek(m);
    vector<vector<int>> Bitek_front(k + 1);
    vector<vector<int>> Bitek_back(k + 1);
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
    for (int i = 0; i < m; i++)
    {
        int val = Bitek[i];
        Bitek_front[val].push_back(i);
        Bitek_back[val].push_back(m - 1 - i);
    }

    for (int i = 0; i < n; i++)
    {
        int val = Bajtek[i];
        int front = distance_front[i];
        int back = distance_back[i];
        int index_b = 0, index_f = 0;

        binary_f(front, Bitek_front[val], 0, Bitek_front[val].size() - 1, index_f);
        binary_b(back, Bitek_back[val], 0, Bitek_back[val].size() - 1, index_b);
        if (index_b <= index_f)
            visited[i] = 1;
    }

    for (auto el : visited)
        cout << el << " ";
    return 0;
}