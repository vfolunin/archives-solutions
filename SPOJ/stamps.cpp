#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int targetSum, friendCount;
    cin >> targetSum >> friendCount;

    vector<int> stamps(friendCount);
    for (int &s : stamps)
        cin >> s;
    sort(stamps.rbegin(), stamps.rend());

    int res = 0, sum = 0;
    while (res < friendCount && sum < targetSum) {
        sum += stamps[res];
        res++;
    }

    cout << "Scenario #" << test << ":\n";
    if (sum >= targetSum)
        cout << res << "\n\n";
    else
        cout << "impossible\n\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}