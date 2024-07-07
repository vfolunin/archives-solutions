#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    double vTotal, v0;
    cin >> vTotal >> v0;

    if (!vTotal && !v0)
        return 0;

    vector<pair<double, int>> len;
    for (int i = 1; vTotal / i > v0; i++)
        len.push_back({ i * 0.3 * sqrt(vTotal / i - v0), i });
    sort(len.rbegin(), len.rend());

    if (len.empty() || !len[0].first || len.size() >= 2 && fabs(len[0].first - len[1].first) <= 1e-9)
        cout << "0\n";
    else
        cout << len[0].second << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}