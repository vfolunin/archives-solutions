#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    size = size * 2 + 1;

    vector<vector<int>> a(size, vector<int>(size));
    int y = size / 2, x = size / 2, count = 0;

    for (int len = 1; len <= size; len += 2) {
        static vector<int> dy = { 0, 1, 0, -1 };
        static vector<int> dx = { -1, 0, 1, 0 };

        for (int d = 0; d < dy.size(); d++) {
            int to = len - 1;
            if (d == 0)
                to--;
            else if (d + 1 == dy.size())
                to++;

            for (int i = 0; i < to; i++) {
                a[y][x] = count++;
                y += dy[d];
                x += dx[d];
            }
        }
    }

    for (int y = 0; y < a.size(); y++) {
        for (int x = 0; x < a.size(); x++) {
            cout.width(3);
            cout << a[y][x];
        }
        cout << "\n";
    }
}