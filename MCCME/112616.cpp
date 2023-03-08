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

    int n;
    cin >> n;

    vector<int> cost(n + 1, 1e9);
    vector<pair<int, int>> from(n + 1);

    cost[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int delta : { 1, 5, 6 }) {
            if (i >= delta && cost[i] > cost[i - delta] + 1) {
                cost[i] = cost[i - delta] + 1;
                from[i] = { i - delta, delta };
            }
        }
    }

    vector<int> res;
    for (int i = n; i; i = from[i].first)
        res.push_back(from[i].second);
    sort(res.rbegin(), res.rend());

    cout << res.size() << "\n";
    for (int value : res)
        cout << value << " ";
}