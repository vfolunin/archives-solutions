#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<pair<string, string>> readPairs() {
    int pairCount;
    cin >> pairCount;

    vector<pair<string, string>> pairs(pairCount);
    for (auto &[a, b] : pairs)
        cin >> a >> b;

    return pairs;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<pair<string, string>> goodPairs = readPairs();
    vector<pair<string, string>> badPairs = readPairs();

    int size;
    cin >> size;

    set<pair<string, string>> pairs;
    for (int i = 0; i < size; i++) {
        vector<string> a(3);
        for (string &s : a)
            cin >> s;

        sort(a.begin(), a.end());
        do {
            pairs.insert({ a[0], a[1] });
        } while (next_permutation(a.begin(), a.end()));
    }

    int res = 0;
    for (auto &[a, b] : goodPairs)
        res += !pairs.count({ a, b });
    for (auto &[a, b] : badPairs)
        res += pairs.count({ a, b });

    cout << res;
}