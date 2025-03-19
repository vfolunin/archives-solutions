#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int n;
    cin >> n;

    vector<int> sum(n - 1), from(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> sum[i];
        from[i] = i;

        if (i && sum[i - 1] >= 0) {
            sum[i] += sum[i - 1];
            from[i] = from[i - 1];
        }
    }

    int to = 0;
    for (int i = 1; i < n - 1; i++)
        if (sum[i] > sum[to] || sum[i] == sum[to] && i - from[i] > to - from[to])
            to = i;

    if (sum[to] < 0) {
        cout << "Route " << test << " has no nice parts\n";
    } else {
        cout << "The nicest part of route " << test;
        cout << " is between stops " << from[to] + 1 << " and " << to + 2 << "\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n = 0;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}