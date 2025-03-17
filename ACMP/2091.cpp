#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Counter {
    vector<int> count;
    int uniqueCount = 0;

    Counter() : count(26) {}

    void add(char c, int delta) {
        uniqueCount -= count[c - 'A'] > 0;
        count[c - 'A'] += delta;
        uniqueCount += count[c - 'A'] > 0;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    Counter counter;
    int res = s.size() + 1;

    for (int l = 0, r = 0; r < s.size(); l++) {
        while (r < s.size() && counter.uniqueCount < 26) {
            counter.add(s[r], 1);
            r++;
        }
        if (counter.uniqueCount == 26)
            res = min(res, r - l);
        counter.add(s[l], -1);
    }

    cout << (res <= s.size() ? res : -1);
}