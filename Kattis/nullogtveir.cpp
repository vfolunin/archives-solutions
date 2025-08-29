#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    long long res = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] > '2') {
            res += 1LL << (s.size() - i);
            break;
        } else if (s[i] == '2') {
            res += 1LL << (s.size() - i - 1);
        } else if (s[i] > '0') {
            res += 1LL << (s.size() - i - 1);
            break;
        }
    }

    res += find_if(s.begin(), s.end(), [](char c) {
        return c != '0' && c != '2';
    }) == s.end();

    cout << res;
}