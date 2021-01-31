#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool compare(const pair<char, int> &a, const pair<char, int> &b) {
    return a.second > b.second;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    map<char, int> countMap;

    char c;
    while (cin >> c) {
        if (isalpha(c))
            countMap[toupper(c)]++;
    }

    vector<pair<char, int>> pairs(countMap.begin(), countMap.end());
    stable_sort(pairs.begin(), pairs.end(), compare);
    for (auto &[c, count] : pairs)
        cout << c << " " << count << "\n";
}