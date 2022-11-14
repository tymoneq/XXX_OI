#include <bits/stdc++.h>
// Tymon Tumialis
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
    Zamki.push_back(1);
    for (int i = 0; i < k; i++)
    {
        cin >> a;
        // bfs
        vector<bool> Visited(n + 1);
        vector<long long> distance(n + 1);
        queue<int> q;
        q.push(a);
        Visited[a] = true;
        while (!q.empty())
        {
            int c = q.front();
            q.pop();
            for (auto b : G[c])
            {
                if (!Visited[b.first])
                {
                    distance[b.first] = distance[c] + b.second;
                    Visited[b.first] = true;
                    q.push(b.first);
                }
            }
        }
        for (int castle : Zamki)
        {
            wynik += 2 * distance[castle];
        }
        Zamki.push_back(a);
        cout << wynik << "\n";
    }
    return 0;
}