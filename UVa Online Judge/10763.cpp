#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int pairCount;
    cin >> pairCount;

    if (!pairCount)
        return 0;

    multiset<pair<int, int>> pairs;
    for (int i = 0; i < pairCount; i++) {
        int a, b;
        cin >> a >> b;

        auto it = pairs.find({ b, a });
        if (it != pairs.end())
            pairs.erase(it);
        else
            pairs.insert({ a, b });
    }
    
    cout << (pairs.empty() ? "YES\n" : "NO\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (solve());
}