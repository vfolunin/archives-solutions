#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

struct Counter {
    unordered_map<int, int> count;

    void add(int value, int delta) {
        count[value] += delta;
        if (!count[value])
            count.erase(value);
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, limit;
    cin >> size >> limit;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    Counter counter;
    long long res = 0;

    for (int l = 0, r = 0; r < a.size(); r++) {
        counter.add(a[r], 1);
        while (counter.count.size() > limit)
            counter.add(a[l++], -1);

        res += r - l + 1;
    }

    cout << res;
}