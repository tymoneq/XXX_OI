#include <bits/stdc++.h>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> G(n + 1);
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int maxi = max(a, b);
        int mini = min(a, b);
        G[maxi] = c + G[mini];
    }
    int a, maxi, mini;
    long long wynik = 0;
    vector<int> Z(k + 1);
    Z[0] = 0;
    for (int i = 0; i < k; i++)
    {
        cin >> a;
        for (auto el : Z)
        {
            maxi = max(a, el);
            mini = min(a, el);
            wynik += 2 * (G[maxi] - G[mini]);
        }
        cout << wynik << "\n";
    }
    return 0;
}