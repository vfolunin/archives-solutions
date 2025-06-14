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
    cin.ignore();

    int part = 0;
    vector<int> l(2, 1e9), r(2, -1e9);

    for (int y = 0; y < h; y++) {
        string s;
        getline(cin, s);

        bool found = 0;
        for (int x = 0; x < w; x++) {
            if (s[x] != ' ') {
                l[part] = min(l[part], x);
                r[part] = max(r[part], x);
                found = 1; 
            }
        }

        if (!found)
            part = 1;
    }

    cout << (l[0] <= r[1] && l[1] <= r[0] ? "YES" : "NO");
}