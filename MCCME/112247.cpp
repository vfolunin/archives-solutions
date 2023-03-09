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

    if (s[0] == '-') {
        cout << "-";
        s.erase(s.begin());
    }

    while (s.size() % 4)
        s = "0" + s;

    string res;
    for (int i = 0; i < s.size(); i += 4) {
        int value = 0;
        for (int j = 0; j < 4; j++)
            value = value * 2 + s[i + j] - '0';
        res += value < 10 ? value + '0' : value - 10 + 'A';
    }

    while (res.size() > 1 && res[0] == '0')
        res.erase(res.begin());

    cout << res;
}