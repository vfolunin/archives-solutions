#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int size;
    cin >> size;

    vector<string> a(size);
    for (string &row : a)
        cin >> row;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (a[i][j] != '.')
                continue;

            for (char c = 'A'; 1; c++) {
                bool ok = 1;
                static int di[] = { -1, 0, 1, 0 };
                static int dj[] = { 0, 1, 0, -1 };

                for (int d = 0; ok && d < 4; d++) {
                    int ti = i + di[d], tj = j + dj[d];
                    ok &= ti < 0 || ti >= size || tj < 0 || tj >= size || a[ti][tj] != c;
                }

                if (ok) {
                    a[i][j] = c;
                    break;
                }
            }
        }
    }

    cout << "Case " << test << ":\n";
    for (string &row : a)
        cout << row << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}