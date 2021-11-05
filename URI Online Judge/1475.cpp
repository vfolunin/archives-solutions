#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int lb(vector<int> &v, int x) {
    return lower_bound(v.begin(), v.end(), x) - v.begin();
}

int getPatchLength(vector<int> &holes, int from, int holeCount, int a, int b) {
    vector<int> res(holeCount + 1, 1e9);
    res[0] = 0;

    for (int i = 1; i <= holeCount; i++) {
        int j = max(0, lb(holes, holes[from + i - 1] - a) - from);
        res[i] = min(res[i], res[j] + a);
        j = max(0, lb(holes, holes[from + i - 1] - b) - from);
        res[i] = min(res[i], res[j] + b);
    }

    return res.back();
}

bool solve() {
    int holeCount, length, a, b;
    if (!(cin >> holeCount >> length >> a >> b))
        return 0;

    vector<int> holes(holeCount);
    for (int &hole : holes)
        cin >> hole;

    for (int i = 0; i < holeCount; i++)
        holes.push_back(length + holes[i]);

    int res = 1e9;
    for (int i = 0; i < holeCount; i++)
        res = min(res, getPatchLength(holes, i, holeCount, a, b));

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}