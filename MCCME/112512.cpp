#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    unordered_map<string, int> count;
    string word;
    while (cin >> word)
        count[word]++;

    vector<pair<string, int>> pairs(count.begin(), count.end());
    sort(pairs.begin(), pairs.end(), [](auto &a, auto &b) {
        if (a.second != b.second)
            return a.second > b.second;
        return a.first < b.first;
    });

    for (auto &[word, count] : pairs)
        cout << word << " " << count << "\n";
}