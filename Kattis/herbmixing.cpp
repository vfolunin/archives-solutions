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
    cin >> a >> b;

    int res = min(a, b) * 10;
    a -= min(a, b);

    for (auto &[need, bonus] : vector<pair<int, int>>{ { 3, 10 }, { 2, 3 }, { 1, 1 } }) {
        res += a / need * bonus;
        a %= need;
    }

    cout << res;
}