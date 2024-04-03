#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int teamCount;
    cin >> teamCount;

    vector<pair<int, int>> results(teamCount);
    for (auto &[acCount, time] : results)
        cin >> acCount >> time;

    vector<int> order(results.size());
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int a, int b) {
        if (results[a].first != results[b].first)
            return results[a].first > results[b].first;
        if (results[a].second != results[b].second)
            return results[a].second < results[b].second;
        return a < b;
    });

    for (int i : order)
        cout << i + 1 << " ";
}