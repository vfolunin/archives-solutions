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

    int y = 0, x = 0;
    map<pair<int, int>, int> count;
    count[{ y, x }]++;

    for (char c : s) {
        y += c == 'U';
        y -= c == 'D';
        x += c == 'L';
        x -= c == 'R';

        count[{ y, x }]++;
    }

    int res = 0;
    for (auto &[_, count] : count)
        res += count > 1;

    cout << res;
}