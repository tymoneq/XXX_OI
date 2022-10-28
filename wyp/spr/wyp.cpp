#include <bits/stdc++.h>
// Tymon Tumialis
using namespace std;

struct track
{
    float poz_start = 0;
    float dl = 0;
    float v = 0;
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, D, wyprzedone = 1;
    float V_auto, W, M;
    cin >> n >> D >> W >> M;
    vector<track> poz(n + 1);
    V_auto = W / M;
    for (int i = 1; i <= n; i++)
    {
        float x, d, w, m;
        cin >> x >> d >> w >> m;
        float v = w / m;
        track l;
        l.poz_start = x;
        l.dl = d;
        l.v = v;
        poz[i] = l;
    }
    // liczenie czasu do zrównania się z ostatnim tirem
    // track last_track = poz.back();
    // float time = (last_track.poz_start - last_track.dl) / (V_auto - last_track.v);
    vector<float> contact_time(n + 1);
    for (int i = 1; i <= n; i++)
    {
        track actual_track = poz[i];
        float time = (actual_track.poz_start - actual_track.dl) / (V_auto - actual_track.v);
        contact_time[i] = time;
    }
    vector<float> bypass_time(n + 1);
    for (int i = 1; i <= n; i++)
    {
        track actual_track = poz[i];
        float time = (actual_track.poz_start + D) / (V_auto - actual_track.v);
        bypass_time[i] = time;
    }
    for (int i = 2; i <= n; i++)
    {
        float cont_track_time = contact_time[i];
        float pass_track_time = bypass_time[i - 1];
        if (cont_track_time <= pass_track_time)
            continue;
        else
        {
            // float poz_first_track_front = pass_track_time * poz[i - 1].v;
            // float poz_second_track_back = cont_track_time * poz[i].v;
            // if (D <= poz_first_track_front - poz_second_track_back)
                wyprzedone += 1;
        }
    }
    cout << wyprzedone << "\n";
    return 0;
}