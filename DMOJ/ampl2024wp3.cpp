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

    vector<pair<int, int>> pairs(10);
    for (auto &[a, b] : pairs)
        cin >> a;
    for (auto &[a, b] : pairs)
        cin >> b;

    int res = 1e9;
    string mask = string(4, '0') + "1" + string(4, '2') + "3";
    do {
        int cur = 0;
        for (int i = 0; i < pairs.size(); i++) {
            if (mask[i] == '0')
                cur += pairs[i].first;
            else if (mask[i] == '1')
                cur += pairs[i].second;
            else if (mask[i] == '2')
                cur -= pairs[i].first;
            else
                cur -= pairs[i].second;
        }
        res = min(res, abs(cur));
    } while (next_permutation(mask.begin(), mask.end()));

    cout << res;
}