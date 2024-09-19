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

    int h, w;
    cin >> h >> w;

    vector<int> count(w);
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            char c;
            cin >> c;
            count[x] += c == 'S';
        }
    }

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++)
            cout << (y < h - count[x] ? "." : "S");
        cout << "\n";
    }
}