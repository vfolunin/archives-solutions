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

    string s;
    getline(cin, s);
    s += '\n';

    vector<string> symbols = {
        "ABCDEF",
        "GHIJKL",
        "MNOPQR",
        "STUVWX",
        "YZ -.\n"
    };

    int py = 0, px = 0, res = 0;
    for (char c : s) {
        for (int y = 0; y < symbols.size(); y++) {
            for (int x = 0; x < symbols[y].size(); x++) {
                if (c == symbols[y][x]) {
                    res += abs(py - y) + abs(px - x);
                    py = y;
                    px = x;
                }
            }
        }
    }

    cout << res;
}