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

    string res;
    for (int i = s.size() - 1; i >= 0; i--) {
        int value = isdigit(s[i]) ? s[i] - '0' : s[i] - 'A' + 10;
        for (int bit = 0; bit < 4; bit++) {
            res += value % 2 + '0';
            value /= 2;
        }
    }
    while (res.size() > 1 && res.back() == '0')
        res.pop_back();
    reverse(res.begin(), res.end());

    cout << res;
}