#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Counter {
    vector<int> count;
    int needCount, zeroCount;
    long long sum = 0;

    Counter(int size, int needCount) : count(size + 1), needCount(needCount), zeroCount(needCount) {}

    void add(int value, int delta) {
        zeroCount -= value <= needCount && !count[value];
        sum -= 1LL * count[value] * value;
        count[value] += delta;
        zeroCount += value <= needCount && !count[value];
        sum += 1LL * count[value] * value;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, needCount;
    cin >> size >> needCount;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    Counter counter(size, needCount);
    long long res = 1e18;
    for (int l = 0, r = 0; r < a.size(); r++) {
        counter.add(a[r], 1);
        while (!counter.zeroCount) {
            res = min(res, counter.sum);
            counter.add(a[l], -1);
            l++;
        }
    }

    cout << res;
}