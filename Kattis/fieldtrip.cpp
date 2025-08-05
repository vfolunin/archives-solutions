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

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int size;
    cin >> size;

    vector<long long> p(size);
    for (long long &value : p)
        cin >> value;

    partial_sum(p.begin(), p.end(), p.begin());

    if (p.back() % 3) {
        cout << -1;
        return 0;
    }

    auto it1 = find(p.begin(), p.end(), p.back() / 3);
    auto it2 = find(p.begin(), p.end(), p.back() / 3 * 2);

    if (it1 != p.end() && it2 != p.end())
        cout << it1 - p.begin() + 1 << " " << it2 - p.begin() + 1;
    else
        cout << -1;
}