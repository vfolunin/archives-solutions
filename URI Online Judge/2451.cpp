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

    vector<string> a(size);
    for (string &row : a)
        cin >> row;

    int res = 0, cur = 0;
    for (int y = 0, x = 0, dx = 1; y < size; y++, dx = -dx) {
        for (; 0 <= x && x < size; x += dx) {
            if (a[y][x] == 'A')
                cur = 0;
            else if (a[y][x] == 'o')
                cur++;
            res = max(res, cur);
        }
        x -= dx;
    }

    cout << res << "\n";
}