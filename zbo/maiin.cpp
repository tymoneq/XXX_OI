#include <bits/stdc++.h>
// Tymon Tumialis
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k, a, b, c, max_w, min_w;

    cin >> n >> k;
    // vector przechowuje wartość do głównego zamku i wszystki wioski na drodze
    vector<pair<int, int>> G(n + 1);
    vector<int> g(n + 1); // ilość drug wychodzących z danego wierzchołka
    bool one_street = true;
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b >> c;
        max_w = max(a, b);
        min_w = min(a, b);
        G[max_w].first = G[min_w].first + c;
        G[max_w].second = min_w;
        g[min_w] += 1;
        if (g[min_w] > 1)
            one_street = false;
    }

    unsigned long long osada, wynik = 0, current_city;
    // tworzymy wektor gdzie będą zapisywane wszystkie miasta
    vector<int> krol;
    for (int i = 0; i < k; i++)
    {
        cin >> osada;
        if (i == 0)

            wynik += G[osada].first * 2;

        else
        {
            wynik += 2 * G[osada].first;
            // sprawdzamy jaki jest najbliższy punkt między miastem z zapytaniem i innymi miastami w vectorze krol
            for (int j = 0; j < krol.size(); j++)
            {
                current_city = krol[j];
                if (one_street)
                {
                    wynik += (max(osada, current_city) - min(osada, current_city)) * 2;
                }
            }
        }
        krol.push_back(osada);
        cout << wynik << "\n";
    }
    return 0;
}