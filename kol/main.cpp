#include <bits/stdc++.h>

using namespace std;
// sprawdz ustawianie tablicy na -1
int matrix[2000][2000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int m, p, n, x, y, type, num_collected = 0;
    char oper;
    cin >> m >> p >> n;
    // typ konkretnego elementu w snake'u
    vector<int> snake_type(p);
    snake_type[0] = 0;
    // początkowa pozycja węża
    list<pair<int, int>> snake_pos(p);

    snake_pos.push_front(make_pair(1, 1));

    // ustawienie wartości na -1
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            matrix[i][j] = -1;

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
            bool visited = false;
            cin >> x >> y;
            int k = num_collected;

            // dodaj quick sorta i binary searcha zamiast tego fora 
            for (auto el : snake_pos)
            {

                if (el.first == x && el.second == y)
                {
                    cout << snake_type[k] << "\n";
                    visited = true;
                    break;
                }
                --k;
            }
            if (!visited)
                cout << -1 << "\n";
        }
        else if (oper == 'P')
        {

            snake_pos.push_front(make_pair(snake_pos.front().first, snake_pos.front().second + 1));

            if (matrix[snake_pos.front().first][snake_pos.front().second] != -1)
            {
                num_collected += 1;
                snake_type[num_collected] = matrix[snake_pos.front().first][snake_pos.front().second];
                matrix[snake_pos.front().first][snake_pos.front().second] = -1;
            }
            else
                snake_pos.pop_back();
        }
        else if (oper == 'L')
        {

            snake_pos.push_front(make_pair(snake_pos.front().first, snake_pos.front().second - 1));
            if (matrix[snake_pos.front().first][snake_pos.front().second] != -1)
            {
                num_collected += 1;
                snake_type[num_collected] = matrix[snake_pos.front().first][snake_pos.front().second];
                matrix[snake_pos.front().first][snake_pos.front().second] = -1;
            }
            else
                snake_pos.pop_back();
        }

        else if (oper == 'D')
        {

            snake_pos.push_front(make_pair(snake_pos.front().first + 1, snake_pos.front().second));
            if (matrix[snake_pos.front().first][snake_pos.front().second] != -1)
            {
                num_collected += 1;
                snake_type[num_collected] = matrix[snake_pos.front().first][snake_pos.front().second];
                matrix[snake_pos.front().first][snake_pos.front().second] = -1;
            }
            else
                snake_pos.pop_back();
        }
        else if (oper == 'G')
        {

            snake_pos.push_front(make_pair(snake_pos.front().first - 1, snake_pos.front().second));
            if (matrix[snake_pos.front().first][snake_pos.front().second] != -1)
            {
                num_collected += 1;
                snake_type[num_collected] = matrix[snake_pos.front().first][snake_pos.front().second];
                matrix[snake_pos.front().first][snake_pos.front().second] = -1;
            }
            else
                snake_pos.pop_back();
        }
    }

    return 0;
}
