#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    string line;
    if (!getline(cin, line))
        return 0;

    vector<vector<int>> a(3, vector<int>(3));

    for (char c : line) {
        int i = (c - 'a') / 3;
        int j = (c - 'a') % 3;

        static int di[] = { -1, 0, 1, 0, 0 };
        static int dj[] = { 0, 1, 0, -1, 0 };

        for (int d = 0; d < 5; d++) {
            int ti = i + di[d];
            int tj = j + dj[d];
            if (0 <= ti && ti <= 2 && 0 <= tj && tj <= 2)
                a[ti][tj] = (a[ti][tj] + 1) % 10;
        }
    }

    cout << "Case #" << test << ":\n";
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cout << a[i][j] << (j < 2 ? ' ' : '\n');
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}