#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    int balance = 0;
    unordered_map<int, int> pos;
    pos[balance] = -1;

    int res = 0;
    for (int i = 0; i < s.size(); i++) {
        balance += s[i] == 'X';
        balance -= s[i] == 'Y';

        if (pos.count(balance))
            res = max(res, i - pos[balance]);
        else
            pos[balance] = i;
    }

    cout << res;
}