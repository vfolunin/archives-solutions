#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string line;
    cin >> line;

    if (line == "*")
        return 0;

    static map<char, int> t = {
        {'W', 64}, {'H', 32}, {'Q', 16}, {'E', 8}, {'S', 4}, {'T', 2}, {'X', 1}
    };

    int measureT = 0, res = 0;
    for (int i = 1; i < line.size(); i++) {
        if (line[i] == '/') {
            res += measureT == 64;
            measureT = 0;
        } else {
            measureT += t[line[i]];
        }
    }

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}