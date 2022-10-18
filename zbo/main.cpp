#include <bits/stdc++.h>
// Tymon Tumialis
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k, a, b, c, max_w, min_w;

    cin >> n >> k;
    // vector przechowuje wartość do głównego zamku i wszystki wioski na drodze
    vector<pair<int, set<int>>> G(n + 1);
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b >> c;
        max_w = max(a, b);
        min_w = min(a, b);
        G[max_w].first = G[min_w].first + c;
        G[max_w].second.insert(G[min_w].second.begin(), G[min_w].second.end());
        G[max_w].second.insert(min_w);
        G[max_w].second.insert(max_w);
    }

    int osada, wynik = 0, miasto;
    // tworzymy wektro gdzie będą zapisywane wszystkie miasta
    vector<int> krol;
    for (int i = 0; i < k; i++)
    {
        cin >> osada;
        if (i == 0)

            wynik += G[osada].first * 2;

        else
        {
            for (int j = 0; j < krol.size(); j++)
            {
                miasto = krol[j];
                wynik += 2 * G[osada].first;
                for (auto city = G[max(miasto, osada)].second.rbegin(); city != G[max(miasto, osada)].second.rend(); city++)
                {

                    if (G[min(miasto, osada)].second.find(*city) != G[min(miasto, osada)].second.end())
                    {
                        auto nearest_point_p = G[min(miasto, osada)].second.find(*city);

                        wynik += (G[max(miasto, osada)].first - G[*nearest_point_p].first + G[min(miasto, osada)].first - G[*nearest_point_p].first) * 2;
                        break;
                    }
                }
            }
        }
        krol.push_back(osada);
        cout << wynik << "\n";
    }
    return 0;
}
