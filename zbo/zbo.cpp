#include <bits/stdc++.h>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<vector<pair<int, int>>> G(n + 1);
    for (int i = 1; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        G[a].push_back(make_pair(b, c));
        G[b].push_back(make_pair(a, c));
    }
    int a, maxi, mini;
    unsigned long long wynik = 0;
    vector<int> Zamki;
    Zamki.push_back(0);
    for (int i = 0; i < k; i++)
    {
        cin >> a;
        for (auto el : Zamki)
        {
            maxi = max(a, el);
            mini = min(a, el);
        }
        Zamki.push_back(a);
        cout << wynik << "\n";
    }
    return 0;
}