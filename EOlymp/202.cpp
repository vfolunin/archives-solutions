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

    vector<int> count(26);
    for (char c : s)
        count[c - 'A']++;

    int res = 0, odd = 0;
    for (int value : count) {
        res += value / 2 * 2;
        odd |= value % 2;
    }

    cout << res + odd;
}