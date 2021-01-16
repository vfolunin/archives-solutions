#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool rec(const vector<int> &a, int step, int res) {
    if (step == 5)
        return res == 23;
    if (rec(a, step + 1, res + a[step]))
        return 1;
    if (rec(a, step + 1, res - a[step]))
        return 1;
    if (rec(a, step + 1, res * a[step]))
        return 1;
    return 0;
}

bool rec(vector<int> &a) {
    sort(a.begin(), a.end());
    do {
        if (rec(a, 1, a[0]))
            return 1;
    } while (next_permutation(a.begin(), a.end()));
    return 0;
}

bool solve() {
    vector<int> a(5);
    for (int &x : a)
        cin >> x;

    if (!a[0])
        return 0;

    cout << (rec(a) ? "Possible\n" : "Impossible\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}