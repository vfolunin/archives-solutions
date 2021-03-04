#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> fromDec(int n, int b) {
    vector<int> res;
    while (n) {
        res.push_back(n % b);
        n /= b;
    }
    reverse(res.begin(), res.end());
    return res;
}

long long toDec(vector<int> n, int b) {
    long long res = 0;
    for (int d : n) {
        if (d >= b)
            return -1;
        res = res * b + d;
    }
    return res;
}

void solve() {
    int base1, base2, l, r;
    cin >> base1 >> base2 >> l >> r;

    for (int n1 = r - 1; n1 > l; n1--) {
        long long n2 = toDec(fromDec(n1, base1), base2);
        if (n2 != -1 && n2 % n1 == 0) {
            cout << n1 << "\n";
            return;
        }
    }

    cout << "Non-existent.\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}