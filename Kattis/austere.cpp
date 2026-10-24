#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int limit;
    cin >> limit >> limit;
    cin.ignore();

    string s;
    getline(cin, s);

    unordered_map<char, int> count;
    for (char c : s)
        if (c != ' ')
            count[c]++;

    vector<pair<char, int>> counts(count.begin(), count.end());
    sort(counts.begin(), counts.end(), [](auto &a, auto &b) {
        return a.second > b.second;
    });

    unordered_set<int> symbols;
    for (int i = 0; i < counts.size() && i < limit; i++)
        symbols.insert(counts[i].first);

    for (char &c : s)
        if (c != ' ' && !symbols.contains(c))
            c = *symbols.begin();

    cout << s;
}