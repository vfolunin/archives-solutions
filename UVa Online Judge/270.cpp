#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

void solve(int test) {
    vector<int> xs, ys;
    while (1) {
        string line;
        if (!getline(cin, line) || line.empty())
            break;

        stringstream ss(line);
        int x, y;
        ss >> x >> y;
        xs.push_back(x);
        ys.push_back(y);
    }

    int res = 0;
    for (int i = 0; i < xs.size(); i++) {
        map<pair<int, int>, int> count;
        int maxCount = 0;
        for (int j = 0; j < xs.size(); j++) {
            if (i == j)
                continue;
            int dx = xs[i] - xs[j], dy = ys[i] - ys[j], d = gcd(dx, dy);
            maxCount = max(maxCount, ++count[{dx / d, dy / d}]);
        }
        res = max(res, maxCount + 1);
    }

    if (test)
        cout << "\n";
    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    cin.ignore(2);

    for (int i = 0; i < n; i++)
        solve(i);
}