#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool compareNumbers(const string &a, const string &b) {
    if (a.size() != b.size())
        return a.size() > b.size();
    return a > b;
}

bool compareParts(const string &a, const string &b) {
    return compareNumbers(a + b, b + a);
}

bool solve() {
    int partCount;
    cin >> partCount;

    if (!partCount)
        return 0;

    vector<string> parts(partCount);
    for (string &part : parts)
        cin >> part;

    sort(parts.begin(), parts.end(), compareParts);

    for (string &part : parts)
        cout << part;
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}