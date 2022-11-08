#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    int a, b, c;
    unsigned long long wynik = 0;
    cin >> n >> k;
    vector<vector<pair<int, int>>> G(n + 1);
    vector<int> more_than_one(n + 1);
    bool more_than__one = false;
    vector<int> Zamki;
    Zamki.push_back(1);
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b >> c;
        G[a].push_back(make_pair(b, c));
        G[b].push_back(make_pair(a, c));
        more_than_one[a] += 1;
        more_than_one[b] += 1;
        if (more_than_one[a] > 2)
            more_than__one = true;
        if (more_than_one[b] > 2)
            more_than__one = true;
    }

    if (more_than__one)
    {
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
    }
    else
    {
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
        for (int i = 0; i < k; i++)
        {
            cin >> a;
                }
    }
    return 0;
}