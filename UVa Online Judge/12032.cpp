#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(vector<int> &xs, int strength) {
    for (int i = 1; i < xs.size(); i++) {
        if (xs[i] - xs[i - 1] > strength)
            return 0;
        if (xs[i] - xs[i - 1] == strength)
            strength--;
    }
    return 1;
}

void solve(int test) {
    int n;
    cin >> n;

    vector<int> xs(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> xs[i];
    
    int l = 0, r = 1e9;
    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (can(xs, m))
            r = m;
        else
            l = m;
    }

    cout << "Case " << test << ": " << r << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}