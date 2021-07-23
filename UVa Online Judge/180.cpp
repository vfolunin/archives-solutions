#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getJoseph() {
    vector<int> res(1e6);
    for (int n = 1; n < res.size(); n++)
        res[n] = (res[n - 1] + 15) % n;
    return res;
}

bool solve() {
    int l, r;
    cin >> l >> r;

    if (!l && !r)
        return 0;

    static vector<int> joseph = getJoseph();

    vector<int> safe(r + 1, 1);
    for (int i = l; i <= r; i++)
        safe[joseph[i]] = safe[(i - joseph[i]) % i] = 0;

    for (int i = 1; i < (l + 1) / 2; i++) {
        if (safe[i]) {
            cout << i << "\n";
            return 1;
        }
    }

    cout << "Better estimate needed\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}