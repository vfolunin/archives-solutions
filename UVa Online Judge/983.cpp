#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int size1, size2;
    if (!(cin >> size1 >> size2))
        return 0;

    vector<vector<int>> p(size1, vector<int>(size1));
    for (int y = 0; y < size1; y++) {
        for (int x = 0; x < size1; x++) {
            cin >> p[y][x];
            if (y)
                p[y][x] += p[y - 1][x];
            if (x)
                p[y][x] += p[y][x - 1];
            if (y && x)
                p[y][x] -= p[y - 1][x - 1];
        }
    }

    if (test)
        cout << "\n";
    int totalSum = 0;
    for (int y1 = 0, y2 = size2 - 1; y2 < size1; y1++, y2++) {
        for (int x1 = 0, x2 = size2 - 1; x2 < size1; x1++, x2++) {
            int sum = p[y2][x2];
            if (y1)
                sum -= p[y1 - 1][x2];
            if (x1)
                sum -= p[y2][x1 - 1];
            if (y1 && x1)
                sum += p[y1 - 1][x1 - 1];
            cout << sum << "\n";
            totalSum += sum;
        }
    }
    cout << totalSum << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int i = 0; solve(i); i++);
}