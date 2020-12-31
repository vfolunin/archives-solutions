#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string line;
    if (!getline(cin, line))
        return 0;

    map<char, int> occurences;
    int maxOccurences = 0;
    for (char c : line)
        if (isalpha(c))
            maxOccurences = max(maxOccurences, ++occurences[c]);

    for (auto &[c, k] : occurences)
        if (k == maxOccurences)
            cout << c;
    cout << " " << maxOccurences << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}