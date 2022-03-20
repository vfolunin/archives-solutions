#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string line;
    if (!getline(cin, line))
        return 0;

    vector<int> count(2);
    for (char c : line)
        for (int bit = 0; bit < 7; bit++)
            count[(c >> bit) & 1]++;

    cout << (count[0] % 2 || count[1] % 2 ? "trapped\n" : "free\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}