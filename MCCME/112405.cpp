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

    map<char, int> count;
    double totalCount = 0;

    char c;
    while (cin >> c) {
        if (isalpha(c)) {
            count[tolower(c)]++;
            totalCount++;
        }
    }

    vector<pair<char, double>> pairs;
    for (auto &[c, count] : count)
        pairs.push_back({ c, count / totalCount });

    sort(pairs.begin(), pairs.end(), [](auto &a, auto &b) {
        if (a.second != b.second)
            return a.second > b.second;
        return a.first < b.first;
    });

    cout.precision(3);
    for (auto &[c, ratio] : pairs)
        cout << c << " " << fixed << ratio << "\n";
}