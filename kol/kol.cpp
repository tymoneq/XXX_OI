#include <bits/stdc++.h>
// Tymon Tumialis
using namespace std;
// Z 26 77
int matrix[2000][2000];
long long czas[2000][2000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int m, p, n, x, y, type;
    char oper;
    cin >> m >> p >> n;
    int new_x = 1;
    int new_y = 1;
    // typ konkretnego elementu w snake'u
    vector<int> snake_type;
    snake_type.push_back(0);
    // ustawienie wartości na -1
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
        {
            matrix[i][j] = -1;
            czas[i][j] = -1;
        }

    // początkowa pozycja węża
    czas[1][1] = 0;

    // wczytanie danych do macierzy
    for (int i = 0; i < p; i++)
    {
        cin >> x >> y >> type;
        matrix[x][y] = type;
    }

    for (int i = 0; i < n; i++)
    {

        cin >> oper;
        if (oper == 'Z')
        {

            cin >> x >> y;
            long long time = czas[x][y];
            if (time == -1)
                cout << -1 << "\n";
            else
            {
                long long current = czas[new_x][new_y];
                long long size = snake_type.size();
                if (current - time >= snake_type.size())
                    cout << -1 << "\n";
                else
                    cout << snake_type[snake_type.size() - (current - time) - 1] << "\n";
            }
        }
        else if (oper == 'P')
        {
            new_y += 1;
            czas[new_x][new_y] = czas[new_x][new_y - 1] + 1;
            if (matrix[new_x][new_y] != -1)
            {
                snake_type.push_back(matrix[new_x][new_y]);
                matrix[new_x][new_y] = -1;
            }
        }
        else if (oper == 'L')
        {
            new_y -= 1;
            czas[new_x][new_y] = 0;
            czas[new_x][new_y] = czas[new_x][new_y + 1] + 1;
            if (matrix[new_x][new_y] != -1)
            {
                snake_type.push_back(matrix[new_x][new_y]);
                matrix[new_x][new_y] = -1;
            }
        }

        else if (oper == 'D')
        {
            new_x += 1;
            czas[new_x][new_y] = 0;
            czas[new_x][new_y] = czas[new_x - 1][new_y] + 1;
            if (matrix[new_x][new_y] != -1)
            {
                snake_type.push_back(matrix[new_x][new_y]);
                matrix[new_x][new_y] = -1;
            }
        }
        else if (oper == 'G')
        {
            new_x -= 1;
            czas[new_x][new_y] = 0;
            czas[new_x][new_y] = czas[new_x + 1][new_y] + 1;
            if (matrix[new_x][new_y] != -1)
            {
                snake_type.push_back(matrix[new_x][new_y]);
                matrix[new_x][new_y] = -1;
            }
        }
    }

    return 0;
}