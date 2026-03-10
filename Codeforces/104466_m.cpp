#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool rec(vector<int> &a, int i, int cur, int target) {
    if (cur == target)
        return 1;
    if (i == a.size())
        return 0;

    return (rec(a, i + 1, cur + a[i], target) ||
        rec(a, i + 1, cur - a[i], target) ||
        rec(a, i + 1, a[i] - cur, target) ||
        rec(a, i + 1, cur * a[i], target) ||
        cur % a[i] == 0 && rec(a, i + 1, cur / a[i], target) ||
        cur && a[i] % cur == 0 && rec(a, i + 1, a[i] / cur, target));
}

bool check(vector<int> a, int target) {
    do {
        if (rec(a, 1, a[0], target))
            return 1;
    } while (next_permutation(a.begin(), a.end()));
    return 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int target;
    cin >> target;

    vector<int> a(3);
    for (a[0] = 1; a[0] <= 100; a[0]++) {
        for (a[1] = a[0] + 1; a[1] <= 100; a[1]++) {
            for (a[2] = a[1] + 1; a[2] <= 100; a[2]++) {
                if (!check(a, target)) {
                    cout << a[0] << " " << a[1] << " " << a[2];
                    return 0;
                }
            }
        }
    }
}