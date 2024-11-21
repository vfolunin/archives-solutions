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

    for (int y = 0, type = 0; y < h; y++) {
        string s;
        cin >> s;

        if ((w - s.size()) % 2) {
            cout << string((w - s.size()) / 2 + type, '.') << s << string((w - s.size()) / 2 + !type, '.') << "\n";
            type ^= 1;
        } else {
            cout << string((w - s.size()) / 2, '.') << s << string((w - s.size()) / 2, '.') << "\n";
        }
    }
}