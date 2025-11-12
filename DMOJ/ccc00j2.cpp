#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isGood(int n) {
    string s = to_string(n);
    reverse(s.begin(), s.end());

    for (char &c : s) {
        if (c == '6' || c == '9')
            c = '6' + '9' - c;
        else if (c != '0' && c != '1' && c != '8')
            return 0;
    }

    return stoi(s) == n;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int l, r;
    cin >> l >> r;

    int res = 0;
    for (int i = l; i <= r; i++)
        res += isGood(i);

    cout << res;
}