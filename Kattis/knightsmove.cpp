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

    char x, y;
    cin >> x >> y;

    set<string> res;
    vector<int> dx = { -1, 1, 2, 2, 1, -1, -2, -2 };
    vector<int> dy = { -2, -2, -1, 1, 2, 2, 1, -1 };

    for (int d = 0; d < dy.size(); d++) {
        char tx = x + dx[d];
        char ty = y + dy[d];
        if ('a' <= tx && tx <= 'h' && '1' <= ty && ty <= '8')
            res.insert(string(1, tx) + ty);
    }

    for (const string &s : res)
        cout << s << "\n";
}