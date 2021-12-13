#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string s;
    if (!(cin >> s))
        return 0;

    vector<int> count(10);
    for (char c : s)
        count[c - '0']++;

    int maxCount = *max_element(count.begin(), count.end());
    int maxDigit = 9;
    while (count[maxDigit] != maxCount)
        maxDigit--;

    cout << maxDigit << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}