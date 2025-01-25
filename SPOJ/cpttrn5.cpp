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

    for (int y = 0; y < h; y++) {
        cout << string(w * (size + 1) + 1, '*') << "\n";
        for (int i = 0; i < size; i++) {
            cout << "*";
            for (int x = 0; x < w; x++) {
                for (int j = 0; j < size; j++) {
                    if ((y + x) % 2)
                        cout << (i + j == size - 1 ? "/" : ".");
                    else
                        cout << (i == j ? "\\" : ".");
                }
                cout << "*";
            }
            cout << "\n";
        }
    }
    cout << string(w * (size + 1) + 1, '*') << "\n\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}