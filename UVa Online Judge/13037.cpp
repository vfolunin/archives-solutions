#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    vector<int> k(3);
    cin >> k[0] >> k[1] >> k[2];

    map<int, set<int>> owners;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < k[i]; j++) {
            int x;
            cin >> x;
            owners[x].insert(i);
        }
    }

    vector<int> has(3), hasNot(3);
    for (auto &[_, s] : owners) {
        if (s.size() == 1)
            has[*s.begin()]++;
        if (s.size() == 2)
            hasNot[3 - *s.begin() - *next(s.begin())]++;
    }

    cout << "Case #" << test << ":\n";
    for (int i = 0; i < 3; i++)
        cout << has[i] << " " << hasNot[i] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}