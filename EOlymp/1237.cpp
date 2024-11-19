#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int digitProduct(const string &s) {
    int res = 1;
    for (char c : s)
        res *= c - '0';
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    int res = digitProduct(s);

    for (int i = (int)s.size() - 2; i >= 0; i--) {
        if (s[i] > '1') {
            string candidate = s;
            candidate[i]--;
            fill(candidate.begin() + i + 1, candidate.end(), '9');

            res = max(res, digitProduct(candidate));
        }
    }

    res = max(res, digitProduct(string(s.size() - 1, '9')));

    cout << res;
}