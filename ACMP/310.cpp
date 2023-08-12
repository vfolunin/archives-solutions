#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int h, w, size;
    cin >> h >> w >> size;

    cout << (h % size == 0 && (w - 2) % size == 0 ||
            (h - 2) % size == 0 && w % size == 0 ||
            (h - 1) % size == 0 && (w - 1) % size == 0 ||
            (h - 1) % size == 0 && w % size == 0 && (w - 2) % size == 0 ||
            h % size == 0 && (h - 2) % size == 0 && (w - 1) % size == 0);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}