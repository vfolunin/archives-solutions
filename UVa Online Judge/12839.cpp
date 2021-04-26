#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int itemCount, queueCount;
    cin >> itemCount >> queueCount;

    vector<long long> item(itemCount);
    for (long long &x : item)
        cin >> x;
    sort(item.begin(), item.end());

    vector<long long> processTime(queueCount);
    for (long long &x : processTime)
        cin >> x;

    set<pair<long long, int>> q;
    for (int qi = 0; qi < queueCount; qi++)
        q.insert({ 0, qi });

    long long res = 0;
    while (!item.empty()) {
        auto [freeTime, qi] = *q.begin();
        res = max(res, item.back() + freeTime);
        item.pop_back();
        q.erase(q.begin());
        q.insert({ freeTime + processTime[qi], qi });
    }

    cout << "Case " << test << ": " << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}