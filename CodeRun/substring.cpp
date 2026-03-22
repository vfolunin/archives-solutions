#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

struct Counter {
    unordered_map<char, int> count;
    int limit, frequentCount = 0;

    Counter(int limit) : limit(limit) {}

    void add(char c, int delta) {
        frequentCount -= count[c] > limit;
        count[c] += delta;
        frequentCount += count[c] > limit;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, limit;
    string s;
    cin >> size >> limit >> s;

    Counter counter(limit);
    int resL = 0, resR = 0;

    for (int l = 0, r = 0; r < size; r++) {
        counter.add(s[r], 1);

        while (counter.frequentCount) {
            counter.add(s[l], -1);
            l++;
        }

        if (resR - resL < r - l) {
            resL = l;
            resR = r;
        }
    }

    cout << resR - resL + 1 << " " << resL + 1;
}