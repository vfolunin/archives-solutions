#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    const int SIDE = 3;
    const int SIZE = SIDE * SIDE;

    vector<vector<int>> a(SIZE, vector<int>(SIZE));
    for (int i = 0; i < SIDE; i++) {
        for (int j = 0; j < SIDE; j++) {
            a[i * SIDE + j][i * SIDE + j] = 1;
            if (i > 0)
                a[i * SIDE + j][(i - 1) * SIDE + j] = 1;
            if (i < SIDE - 1)
                a[i * SIDE + j][(i + 1) * SIDE + j] = 1;
            if (j > 0)
                a[i * SIDE + j][i * SIDE + j - 1] = 1;
            if (j < SIDE - 1)
                a[i * SIDE + j][i * SIDE + j + 1] = 1;
        }
    }

    vector<int> b(SIZE);
    for (int i = 0; i < SIDE; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < SIDE; j++)
            if (line[j] == '*')
                b[i * SIDE + j] = 1;
    }

    for (int col = 0, row = 0; col < SIZE && row < SIZE; col++) {
        int bestRow = row;
        for (int i = row + 1; i < SIZE; i++)
            if (a[i][col] > a[bestRow][col])
                bestRow = i;

        if (a[bestRow][col] == 0)
            continue;

        for (int j = 0; j < SIZE; j++)
            swap(a[row][j], a[bestRow][j]);
        swap(b[row], b[bestRow]);

        for (int i = 0; i < SIZE; i++) {
            if (i == row || a[i][col] == 0)
                continue;
            for (int j = col; j < SIZE; j++)
                a[i][j] ^= a[row][j];
            b[i] ^= b[row];
        }

        row++;
    }

    cout << count(b.begin(), b.end(), 1) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}