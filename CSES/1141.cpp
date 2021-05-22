#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Counter {
    map<int, int> count;
    int duplicateCount = 0;

    void inc(int x) {
        duplicateCount += count[x]++ == 1;
    }

    void dec(int x) {
        duplicateCount -= --count[x] == 1;
    }

    bool ok() {
        return !duplicateCount;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int songCount;
    cin >> songCount;

    vector<int> songs(songCount);
    for (int &song : songs)
        cin >> song;

    Counter counter;
    int res = 0;
    for (int l = 0, r = 0; r < songCount; r++) {
        counter.inc(songs[r]);
        while (!counter.ok())
            counter.dec(songs[l++]);
        res = max(res, r - l + 1);
    }

    cout << res;
}