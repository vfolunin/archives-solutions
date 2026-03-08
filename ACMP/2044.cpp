#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string toBin(long long value) {
    string res;
    for (; value; value /= 2)
        res += value % 2 + '0';
    reverse(res.begin(), res.end());
    return res;
}

long long toDec(string &s) {
    long long res = 0;
    for (char c : s)
        res = res * 2 + c - '0';
    return res;
}

long long process(long long value) {
    string s = toBin(value);
    if (value % 2)
        s = "1" + s + "10";
    else
        s = "11" + s;
    return toDec(s);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int l, r;
    cin >> l >> r;

    long long res = 0;
    for (int i = max(l, r - 10); i <= r; i++)
        res = max(res, process(i));

    cout << res;
}