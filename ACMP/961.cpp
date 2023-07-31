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

    vector<string> a(h);
    for (string &row : a)
        cin >> row;

    set<char> res;
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            char c;
            cin >> c;
            if (a[y][x] != c && isalpha(c))
                res.insert(c);
        }
    }

    cout << res.size() << "\n";
    for (char c : res)
        if (islower(c))
            cout << c;
    for (char c : res)
        if (isupper(c))
            cout << c;
}