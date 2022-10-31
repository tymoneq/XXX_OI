#include <bits/stdc++.h>

using namespace std;
struct track
{
    double poz_start = 0;
    double dl = 0;
    double v = 0;
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, wyprzedone = 1;
    double V_auto, W, M, D;
    cin >> n >> D >> W >> M;
    vector<pair<double, int>> V_mal;     // first = V second = index
    vector<pair<double, int>> V_te_same; // first = V second = index
    vector<track> poz(n + 1);
    vector<pair<int, int>> indeksy_policzone;
    V_auto = W / M;
    for (int i = 1; i <= n; i++)
    {
        double x, d, w, m;
        cin >> x >> d >> w >> m;
        double v = w / m;
        track l;
        l.poz_start = x;
        l.dl = d;
        l.v = v;
        poz[i] = l;
    }
    // znalezienie pierwszej mniejszej prędkości od tyłu
    int index = 1;
    for (int i = n; i >= 2; i--)
    {
        if (poz[i].v < poz[i - 1].v)
        {
            index = i;
            V_mal.push_back(make_pair(poz[i].v, i));
            V_te_same.push_back(make_pair(poz[i].v, i));
            break;
        }
    }
    // znalezienie wszystkich najmniejszych równych V
    for (int i = index - 1; i >= 1; i--)
    {
        if (poz[i].v == V_te_same.back().first)
            V_te_same.push_back(make_pair(poz[i].v, i));
        if (poz[i].v < V_mal.back().first)
            V_mal.push_back(make_pair(poz[i].v, i));
    }

    if (V_te_same.size() != 0)
    {
        for (int i = 0; i < V_te_same.size() - 1; i++)
        {
            if (V_te_same[i].first != V_te_same[i + 1].first)
                continue;
            else
            {
                double dystans = poz[V_te_same[i].second].poz_start - poz[V_te_same[i].second].dl - poz[V_te_same[i + 1].second].poz_start;
                for (int k = V_te_same[i].second - 1; k > V_te_same[i + 1].second; k--)
                    dystans -= poz[k].dl;

                if (dystans < D)
                {
                    indeksy_policzone.push_back(make_pair(V_te_same[i].second, V_te_same[i + 1].second));
                    continue;
                }
                else
                {
                    double previous_time = numeric_limits<int>::max();
                    indeksy_policzone.push_back(make_pair(V_te_same[i].second, V_te_same[i + 1].second));
                    for (int j = V_te_same[i].second - 1; j > V_te_same[i + 1].second; j--)
                    {
                        double time = (poz[j + 1].poz_start - poz[j].poz_start - poz[j + 1].dl - D) / (poz[j].v - poz[j + 1].v);
                        if (time <= previous_time)
                        {
                            double poz_sam = time * V_auto;
                            if (poz_sam >= poz[j + 1].poz_start - poz[j + 1].dl + poz[j + 1].v * time)
                                wyprzedone += 1;
                            previous_time = time;
                        }
                        else
                        {
                            double distans = poz[j + 1].poz_start - poz[j + 1].dl - poz[j].poz_start + poz[j + 1].v * previous_time - poz[j].v * previous_time;
                            if (distans >= D)
                            {
                                double new_time = (distans - D) / (poz[j].v - poz[j + 2].v);
                                double poz_sam = new_time * V_auto;
                                if (poz_sam >= poz[j].poz_start + poz[j].v * previous_time + poz[j].v * new_time)
                                    wyprzedone += 1;
                                previous_time = new_time + previous_time;
                            }
                        }
                    }
                }
            }
        }
    }
    // gdy V_1> V_2
    for (int i = 1; i < index; i++)
    {
    }

    // gdy V_1 <= V_2
    for (int i = index; i < n; i++)
    {
        double time = (poz[i].poz_start + D) / (V_auto - poz[i].v);
        double pocz_pierwszej = poz[i].poz_start + poz[i].v * time;
        double kon_drugiej = poz[i + 1].poz_start - poz[i + 1].dl + poz[i + 1].v * time;
        if (kon_drugiej - pocz_pierwszej >= D)
            wyprzedone += 1;
    }
    cout << wyprzedone;
    return 0;
}