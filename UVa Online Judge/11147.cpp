#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int sum(vector<int> &p, int l, int r) {
    if (l > r)
        return 0;
    return p[r] - (l ? p[l - 1] : 0);
}

string rec(vector<int> &p, int l, int r) {
    if (l == r)
        return to_string(sum(p, l, r));

    int bestRoot = -1, bestA, bestB;
    for (int root = l; root <= r; root++) {
        if (root + 1 <= r && sum(p, root, root) == sum(p, root + 1, root + 1))
            continue;

        int a = sum(p, l, root - 1), b = sum(p, root + 1, r);
        if (bestRoot == -1 || abs(bestA - bestB) > abs(a - b) || abs(bestA - bestB) == abs(a - b) && bestA < a) {
            bestRoot = root;
            bestA = a;
            bestB = b;
        }
    }

    if (bestRoot == l)
        return to_string(sum(p, l, l)) + "(" + rec(p, l + 1, r) + ")";

    if (bestRoot == r)
        return to_string(sum(p, r, r)) + "(" + rec(p, l, r - 1) + ")";

    string res = to_string(sum(p, bestRoot, bestRoot));
    res += "(" + rec(p, l, bestRoot - 1);
    res += "," + rec(p, bestRoot + 1, r) + ")";
    return res;
}

void solve(int test) {
    int size;
    cin >> size;

    vector<int> p(size);
    for (int &x : p)
        cin >> x;
    sort(p.begin(), p.end());
    for (int i = 1; i < size; i++)
        p[i] += p[i - 1];

    cout << "Case #" << test << ": " << rec(p, 0, size - 1) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}