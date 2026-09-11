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

    int balance = 0;
    string res = s;
    for (int i = 0; i < s.size(); i++) {
        balance += s[i] == '(' ? 1 : -1;
        if (!balance) {
            rotate(res.begin(), res.begin() + i + 1, res.end());
            break;
        }
    }

    cout << (res != s ? res : "no");
}