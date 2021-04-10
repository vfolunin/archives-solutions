#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string name;
    cin >> name;

    if (name == "end")
        return 0;

    cout << name << " ";

    int n = 10;
    int size = n * n;

    vector<vector<int>> a(size, vector<int>(size));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i * n + j][i * n + j] = 1;
            if (i > 0)
                a[i * n + j][(i - 1) * n + j] = 1;
            if (i < n - 1)
                a[i * n + j][(i + 1) * n + j] = 1;
            if (j > 0)
                a[i * n + j][i * n + j - 1] = 1;
            if (j < n - 1)
                a[i * n + j][i * n + j + 1] = 1;
        }
    }

    vector<int> b(size);
    for (int i = 0; i < n; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < n; j++)
            if (line[j] == 'O')
                b[i * n + j] = 1;
    }

    for (int col = 0, row = 0; col < size && row < size; col++) {
        int bestRow = row;
        for (int i = row + 1; i < size; i++)
            if (a[i][col] > a[bestRow][col])
                bestRow = i;

        if (a[bestRow][col] == 0)
            continue;

        for (int j = 0; j < size; j++)
            swap(a[row][j], a[bestRow][j]);
        swap(b[row], b[bestRow]);

        for (int i = 0; i < size; i++) {
            if (i == row || a[i][col] == 0)
                continue;
            for (int j = col; j < size; j++)
                a[i][j] ^= a[row][j];
            b[i] ^= b[row];
        }

        row++;
    }

    for (int i = 0; i < size; i++) {
        if (b[i] && !count(a[i].begin(), a[i].end(), 1)) {
            cout << "-1\n";
            return 1;
        }
    }

    int res = count(b.begin(), b.end(), 1);

    cout << (res <= 100 ? res : -1) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}