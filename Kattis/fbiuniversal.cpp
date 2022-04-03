#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const string DIGITS = "0123456789ACDEFHJKLMNPRTVWX";

map<char, char> prepareReplaces() {
    map<char, char> replaces;
    replaces['B'] = '8';
    replaces['G'] = 'C';
    replaces['I'] = '1';
    replaces['O'] = '0';
    replaces['Q'] = '0';
    replaces['S'] = '5';
    replaces['U'] = 'V';
    replaces['Y'] = 'V';
    replaces['Z'] = '2';
    return replaces;
}

void normalize(string &s) {
    static map<char, char> replaces = prepareReplaces();
    for (char &c : s)
        if (replaces.count(c))
            c = replaces[c];
}

bool isValid(string &s) {
    static vector<int> weights = { 2, 4, 5, 7, 8, 10, 11, 13 };
    int sum = 0;
    for (int i = 0; i < weights.size(); i++)
        sum += weights[i] * DIGITS.find(s[i]);
    return s.back() == DIGITS[sum % DIGITS.size()];
}

long long toDec(string &s) {
    long long res = 0;
    for (int i = 0; i + 1 < s.size(); i++)
        res = res * DIGITS.size() + DIGITS.find(s[i]);
    return res;
}

void solve() {
    int test;
    string s;
    cin >> test >> s;

    normalize(s);

    cout << test << " ";
    if (isValid(s))
        cout << toDec(s) << "\n";
    else
        cout << "Invalid\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}