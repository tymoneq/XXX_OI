#include <bits/stdc++.h>
using namespace std;
int main()
{
    ofstream file;
    file.open("test.in");
    file << 100000 << " " << 99999 << "\n";
    for (int i = 1; i <= 100000; i++)
    {
        file << i << " " << i + 1 << " " << 1000 << "\n";
    }
    return 0;
}