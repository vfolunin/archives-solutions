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

    char c;
    int w, h, p;
    cin >> c >> w >> h >> p;

    cout << string(w, c) << "\n";
    for (int i = 0; i < p; i++) {
        for (int y = 1; y < h; y++) {
            cout << string(y < h / 2 ? y : h - 1 - y, ' ');
            for (int x = 0; x < w; x++)
                cout << ((i * (h - 1) + y) % 2 && x % 2 ? ' ' : c);
            cout << "\n";
        }
    }
}