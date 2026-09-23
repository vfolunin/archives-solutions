#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    vector<int> a(3);
    for (int &value : a)
        cin >> value;

    int res = 0;
    while (1) {
        sort(a.begin(), a.end());
        if (a[0] == a[1] || a[1] == a[2])
            break;

        a.front()++;
        a.back()--;
        res++;
    }

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}