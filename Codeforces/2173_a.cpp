#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size, threshold;
    string s;
    cin >> size >> threshold >> s;

    int last = -1e9, res = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1')
            last = i;
        else
            res += i - last > threshold;
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