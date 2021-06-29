#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    double x;
    if (!(cin >> x))
        return 0;

    if (x == 1) {
        cout << "MEMBER\n";
        return 1;
    }

    string s;
    for (int i = 0; i < 30; i++) {
        x *= 3;
        int d = x;
        s += '0' + d;
        x -= d;
    }

    while (!s.empty() && s.back() == '0')
        s.pop_back();
    if (!s.empty() && s.back() == '1')
        s.pop_back();

    cout << (count(s.begin(), s.end(), '1') ? "NON-MEMBER\n" : "MEMBER\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}