#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Counter {
    map<char, int> count;
    multiset<int> counts;

    void add(char c, int delta) {
        if (auto it = counts.find(count[c]); it != counts.end())
            counts.erase(it);
        count[c] += delta;
        counts.insert(count[c]);
    }
};

bool can(string &s, int len, int limit) {
    Counter counter;
    for (int i = 0; i < len; i++)
        counter.add(s[i], 1);
    if (len - *counter.counts.rbegin() <= limit)
        return 1;

    for (int i = len; i < s.size(); i++) {
        counter.add(s[i - len], -1);
        counter.add(s[i], 1);
        if (len - *counter.counts.rbegin() <= limit)
            return 1;
    }

    return 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int limit;
    string s;
    cin >> limit >> s;

    int l = 1, r = s.size() + 1;
    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (can(s, m, limit))
            l = m;
        else
            r = m;
    }

    cout << l;
}