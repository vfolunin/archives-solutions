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

    string buttons = "22233344455566677778889999";
    int res = 0;
    for (char c : s)
        res += buttons[c - 'A'] - '2' + 3;

    cout << res;
}