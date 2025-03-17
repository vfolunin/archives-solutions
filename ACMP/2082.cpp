#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
using namespace std;

struct Counter {
    unordered_set<char> letters;
    unordered_map<char, int> count;
    int limit, frequentCount = 0;

    Counter(string &letters, int limit) :
        letters(letters.begin(), letters.end()), limit(limit) {}

    void add(char c, int delta) {
        if (!letters.count(c))
            return;
        frequentCount -= count[c] > limit;
        count[c] += delta;
        frequentCount += count[c] > limit;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s, letters;
    int limit;
    cin >> s >> letters >> limit;

    Counter counter(letters, limit);
    int res = 0;
    for (int l = 0, r = 0; r < s.size(); r++) {
        counter.add(s[r], 1);
        while (counter.frequentCount) {
            counter.add(s[l], -1);
            l++;
        }
        res = max(res, r - l + 1);
    }

    cout << res;
}