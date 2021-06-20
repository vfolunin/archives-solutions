#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> prepare() {
    vector<int> cubes;
    for (int i = 1; i <= 1000; i++)
        cubes.push_back(i * i * i);

    map<int, int> count;
    for (int i = 0; i < cubes.size(); i++)
        for (int j = i; j < cubes.size(); j++)
            count[cubes[i] + cubes[j]]++;

    vector<int> taxicab;
    for (auto &[sum, cnt] : count)
        if (cnt > 1)
            taxicab.push_back(sum);
    return taxicab;
}

bool solve() {
    int l, count, r;
    if (!(cin >> l >> count))
        return 0;
    r = l + count;

    static vector<int> taxicab = prepare();

    auto p = lower_bound(taxicab.begin(), taxicab.end(), l);
    auto q = upper_bound(taxicab.begin(), taxicab.end(), r);

    if (p == q) {
        cout << "None\n";
    } else {
        for (; p != q; p++)
            cout << *p << "\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}