#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getCount() {
    string s;
    cin >> s;

    vector<int> count(26);
    for (char c : s)
        count[c - 'a']++;
    return count;
}

void solve() {
    int aSize, bSize;
    cin >> aSize >> bSize;

    vector<int> aCount = getCount();
    vector<int> bCount = getCount();

    int res = 1e9;
    for (int i = 0; i < aCount.size(); i++)
        if (bCount[i])
            res = min(res, aCount[i] / bCount[i]);

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}