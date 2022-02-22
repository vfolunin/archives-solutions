#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rotateLeft(vector<vector<int>> &a) {
    int n = a.size();
    for (int y = 0; y < n / 2; y++) {
        for (int x = 0; x < n / 2; x++) {
            swap(a[y][x], a[x][n - 1 - y]);
            swap(a[x][n - 1 - y], a[n - 1 - y][n - 1 - x]);
            swap(a[n - 1 - y][n - 1 - x], a[n - 1 - x][y]);
        }
    }
}

void rotateRight(vector<vector<int>> &a) {
    for (int i = 0; i < 3; i++)
        rotateLeft(a);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<vector<int>> a(4, vector<int>(4));
    for (int y = 0; y < a.size(); y++)
        for (int x = 0; x < a.size(); x++)
            cin >> a[y][x];

    int direction;
    cin >> direction;

    for (int i = 0; i < direction; i++)
        rotateLeft(a);

    for (int y = 0; y < a.size(); y++) {
        fill(remove(a[y].begin(), a[y].end(), 0), a[y].end(), 0);
        for (int x = 0; x + 1 < a.size(); x++) {
            if (a[y][x] && a[y][x] == a[y][x + 1]) {
                a[y][x] *= 2;
                for (int i = x + 1; i + 1 < a.size(); i++)
                    a[y][i] = a[y][i + 1];
                a[y].back() = 0;
            }
        }
    }

    for (int i = 0; i < direction; i++)
        rotateRight(a);

    for (int y = 0; y < a.size(); y++) {
        for (int x = 0; x < a.size(); x++)
            cout << a[y][x] << " ";
        cout << "\n";
    }
}