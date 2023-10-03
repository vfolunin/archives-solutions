#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string fromDec(long long n, int base) {
    static const string DIGITS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string res;
    while (n >= base) {
        res += DIGITS[n % base];
        n /= base;
    }
    res += DIGITS[n];
    reverse(res.begin(), res.end());
    return res;
}

long long toDec(string s, int base) {
    static const string DIGITS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    long long res = 0;
    for (char c : s)
        res = res * base + DIGITS.find(c);
    return res;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	long long n;
	cin >> n;

	string s = fromDec(n, 2);

	set<long long> values;
	for (int l = 0; l < s.size(); l++)
		for (int r = l; r < s.size(); r++)
			values.insert(toDec(s.substr(l, r - l + 1), 2));

	long long res = 0;
	for (long long value : values)
		res += value;

	cout << res;
}