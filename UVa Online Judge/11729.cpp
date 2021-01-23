#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool compare(const pair<int, int> &p1, const pair<int, int> &p2) {
    auto &[a1, b1] = p1;
    auto &[a2, b2] = p2;
    // return b1 > b2;
    return (a1 + max(b1, a2 + b2) < a2 + max(b2, a1 + b1));
}

bool solve(int test) {
    int n;
    cin >> n;

    if (!n)
        return 0;

    vector<pair<int, int>> p(n);
    for (auto &[a, b] : p)
        cin >> a >> b;

    sort(p.begin(), p.end(), compare);

    long long t = 0, maxT = 0;
    for (auto &[a, b] : p) {
        maxT = max(maxT, t + a + b);
        t += a;
    }

    cout << "Case " << test << ": " << maxT << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}