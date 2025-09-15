#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

vector<int> prepare() {
    vector<int> res(1);
    unordered_set<int> values = { res.back() };

    for (int i = 1; i <= 5e5; i++) {
        res.push_back(res.back() > i && !values.count(res.back() - i) ? res.back() - i : res.back() + i);
        values.insert(res.back());
    }

    return res;
}

bool solve() {
    int index;
    cin >> index;

    if (index == -1)
        return 0;

    static vector<int> res = prepare();

    cout << res[index] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}