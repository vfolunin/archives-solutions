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
    cin >> s >> s;

    if (s.size() % 2 || count(s.begin(), s.end(), '(') != s.size() / 2) {
        cout << -1;
        return 0;
    }

    int res = 0, balance = 0, from;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            balance++;
            if (!balance)
                res += i - from + 1;
        } else {
            if (!balance)
                from = i;
            balance--;
        }
    }

    cout << res;
}