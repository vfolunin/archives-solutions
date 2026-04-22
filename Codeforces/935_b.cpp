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

    int x = 0, y = 0, side = 0, res = 0;
    for (char c : s) {
        x += c == 'R';
        y += c == 'U';

        if (x < y) {
            res += side == 2;
            side = 1;
        } else if (x > y) {
            res += side == 1;
            side = 2;
        }
    }

    cout << res;
}