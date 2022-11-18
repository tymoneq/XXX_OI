#include <bits/stdc++.h>
// Tymon Tumialis
using namespace std;
typedef unsigned long long ull;
struct edge_points
{
    int castle = 0;
    ull value = 0;
};
struct last_value
{
    int castle_num = 0;
    ull value = 0;
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<vector<pair<int, int>>> G(n + 1); // first docelowy second droga
    for (int i = 1; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        G[a].push_back(make_pair(b, c));
        G[b].push_back(make_pair(a, c));
    }
    int a;
    ull wynik = 0;
    // if (n * k <= 1000000) // 1 podzadanie
    // {
    //     vector<int> Zamki;
    //     Zamki.push_back(1);
    //     for (int i = 0; i < k; i++)
    //     {
    //         cin >> a;
    //         // bfs
    //         vector<bool> Visited(n + 1);
    //         vector<long long> distance(n + 1);
    //         queue<int> q;
    //         q.push(a);
    //         Visited[a] = true;
    //         while (!q.empty())
    //         {
    //             int c = q.front();
    //             q.pop();
    //             for (auto b : G[c])
    //             {
    //                 if (!Visited[b.first])
    //                 {
    //                     distance[b.first] = distance[c] + b.second;
    //                     Visited[b.first] = true;
    //                     q.push(b.first);
    //                 }
    //             }
    //         }
    //         for (int castle : Zamki)
    //         {
    //             wynik += 2 * distance[castle];
    //         }
    //         Zamki.push_back(a);
    //         cout << wynik << "\n";
    //     }
    // }
    // else // drugie podzadanie
    {
        // bfs
        ull previous_wynik = 0;
        vector<bool> Visited(n + 1);
        vector<int> Dist(n + 1, 0);
        vector<int> Zamki_sort;
        edge_points max_val_up;
        edge_points min_val_down;
        int maxi, mini;
        queue<int> q;
        q.push(1);
        Visited[1] = true;
        while (!q.empty())
        {
            int c = q.front();
            q.pop();
            for (auto b : G[c])
            {
                if (!Visited[b.first])
                {
                    Dist[b.first] = Dist[c] + b.second;
                    Visited[b.first] = true;
                    q.push(b.first);
                }
            }
        }
        last_value last_val;
        bool prev_val_find = false;
        for (int i = 0; i < k; i++)
        {
            cin >> a;

            if (i == 0)
            {
                wynik += Dist[a];
                max_val_up.castle = a;
                max_val_up.value = 0;
                min_val_down.castle = a;
                min_val_down.value = 0;
            }
            else if (i == 1)
            {
                maxi = max(Zamki_sort[0], a);
                mini = min(Zamki_sort[0], a);
                wynik += Dist[a] + Dist[maxi] - Dist[mini];
                max_val_up.castle = maxi;
                max_val_up.value = Dist[maxi] - Dist[mini];
                min_val_down.castle = mini;
                min_val_down.value = Dist[maxi] - Dist[mini];
            }
            else
            {
                if (a < min_val_down.castle)
                {
                    wynik += Dist[a] + min_val_down.value + (Dist[min_val_down.castle] - Dist[a]) * Zamki_sort.size();
                    min_val_down.value += (Dist[min_val_down.castle] - Dist[a]) * Zamki_sort.size();
                    min_val_down.castle = a;
                    max_val_up.value += Dist[max_val_up.castle] - Dist[a];
                    last_val.value += Dist[last_val.castle_num] - Dist[min_val_down.castle];
                    prev_val_find = false;
                }
                else if (a > max_val_up.castle)
                {
                    wynik += Dist[a] + max_val_up.value + (Dist[a] - Dist[max_val_up.castle]) * Zamki_sort.size();
                    max_val_up.value += (Dist[a] - Dist[max_val_up.castle]) * Zamki_sort.size();
                    max_val_up.castle = a;
                    min_val_down.value += Dist[a] - Dist[min_val_down.castle];
                    last_val.value += Dist[max_val_up.castle] - Dist[last_val.castle_num];
                    prev_val_find = false;
                }
                else
                {
                    wynik += Dist[a];
                    if (!prev_val_find)
                    {
                        for (int el : Zamki_sort)
                            wynik += abs(Dist[a] - Dist[el]);

                        prev_val_find = true;
                    }
                    else if (i % 2 == 0)
                        wynik += last_val.value;
                    else
                        wynik += last_val.value + abs(Dist[last_val.castle_num] - Dist[a]);
                    max_val_up.value += Dist[max_val_up.castle] - Dist[a];
                    min_val_down.value += Dist[a] - Dist[min_val_down.castle];
                    last_val.castle_num = a;
                    last_val.value = wynik - previous_wynik - Dist[a];
                }
            }

            previous_wynik = wynik;
            Zamki_sort.push_back(a);
            cout << wynik * 2 << "\n";
        }
    }
    return 0;
}