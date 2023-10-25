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

    int size, moveCount;
    cin >> size >> moveCount;

    int y = 0, x = 0;

    vector<int> dy = { 1, 0, -1, 0 };
    vector<int> dx = { 0, 1, 0, -1 };

    for (int i = 0; i < moveCount; i++) {
        int step;
        cin >> step;

        y += dy[i % dy.size()] * step;
        x += dx[i % dx.size()] * step;

        if (abs(y) >= size || abs(x) >= size) {
            cout << clamp(x, -size, size) << " " << clamp(y, -size, size);
            return 0;
        }
    }

    cout << x << " " << y;
}