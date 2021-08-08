#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    vector<int> a(n);
    for (int &x : a) {
        double d;
        cin >> d;
        x = d * 10 + 1e-9;
    }

    vector<vector<long long>> ways(9, vector<long long>(100));
    ways[0][0] = 1;

    for (int items = 1; items <= 8; items++)
        for (int delta = 0; delta < 100; delta++)
            for (int x : a)
                if (delta >= x % 10)
                    ways[items][delta] += ways[items - 1][delta - x % 10];

    long long res = 0;
    for (int delta = 0; delta < 100; delta++)
        res += ways[8][delta] * (delta / 10);

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}