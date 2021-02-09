#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string decToBin(long long n) {
    string res;
    for (int i = 0; i < 13; i++) {
        res += n % 2 + '0';
        n /= 2;
    }
    reverse(res.begin(), res.end());
    return res;
}

long long hexToDec(string &n) {
    static string digits = "0123456789ABCDEF";
    long long res = 0;
    for (char c : n)
        res = res * 16 + digits.find(c);
    return res;
}

void solve() {
    string as, op, bs;
    cin >> as >> op >> bs;

    long long a = hexToDec(as), b = hexToDec(bs);
    long long res = (op == "+" ? a + b : a - b);

    cout << decToBin(a) << " " << op << " " << decToBin(b) << " = " << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}