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

    for (int size = 1; size < s.size(); size++)
        res += 1LL << size;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '4') {
            res += i == s.size() - 1;
            continue;
        }

        if (s[i] > '4')
            res += 1LL << (s.size() - 1 - i);

        if (s[i] == '7') {
            res += i == s.size() - 1;
            continue;
        }

        if (s[i] > '7')
            res += 1LL << (s.size() - 1 - i);

        break;
    }

    cout << res;
}