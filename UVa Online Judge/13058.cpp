#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool check(vector<int> a, int len, int from) {
    int curLen = 0;
    for (int i = 0; i < a.size(); i++) {
        curLen += a[(from + i) % a.size()];
        if (curLen > len)
            return 0;
        if (curLen == len)
            curLen = 0;
    }
    return 1;
}

bool check(vector<int> a, int len) {
    int curLen = 0;
    for (int i = 0; i < a.size(); i++) {
        curLen += a[i];
        if (curLen > len)
            break;
        if (check(a, len, i))
            return 1;
    }
    return 0;
}

bool solve() {
    int n;
    if (!(cin >> n))
        return 0;

    vector<int> a(n);
    int sum = 0;

    for (int &x : a) {
        cin >> x;
        sum += x;
    }

    for (int d = 1; d * d <= sum; d++) {
        if (sum % d == 0 && check(a, d)) {
            cout << sum / d << "\n";
            return 1;
        }
    }

    cout << "-1\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}