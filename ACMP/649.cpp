#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Counter {
    map<char, int> count;
    int limit, badCount = 0;

    Counter(int limit) : limit(limit) {}

    void add(char c, int delta) {
        badCount -= count[c] > limit;
        count[c] += delta;
        badCount += count[c] > limit;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, limit;
    string s;
    cin >> size >> limit >> s;

    Counter counter(limit);
    long long res = 0;

    for (int l = 0, r = 0; r < s.size(); r++) {
        counter.add(s[r], 1);
        while (counter.badCount)
            counter.add(s[l++], -1);
        res += r - l + 1;
    }

    cout << res;
}