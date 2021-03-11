#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int typeCount, totalLimit;
    cin >> typeCount >> totalLimit;

    vector<int> mangoCount(typeCount);
    for (int &x : mangoCount) {
        cin >> x;
        totalLimit -= x;
    }

    vector<int> mangoLimit(typeCount);
    for (int &x : mangoLimit)
        cin >> x;

    bool can = totalLimit >= 0;
    for (int i = 0; i < typeCount; i++)
        can &= mangoCount[i] <= mangoLimit[i];

    cout << "Case " << test << ": " << (can ? "Yes\n" : "No\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}