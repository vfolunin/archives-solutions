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

    int a, b;
    char x, y;
    cin >> a >> b >> x >> y;

    set<string> res;
    vector<int> dx = { -b, b, a, a, b, -b, -a, -a };
    vector<int> dy = { -a, -a, -b, b, a, a, b, -b };

    for (int d = 0; d < dy.size(); d++) {
        char tx = x + dx[d];
        char ty = y + dy[d];
        if ('a' <= tx && tx <= 'h' && '1' <= ty && ty <= '8')
            res.insert(string(1, tx) + ty);
    }

    cout << res.size() << "\n";
    for (const string &s : res)
        cout << s << " ";
}