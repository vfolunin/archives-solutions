#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Counter {
    vector<int> count;
    int nonZeroCount = 0;

    Counter(int size) : count(size) {}

    void add(int i, int delta) {
        nonZeroCount -= count[i] > 0;
        count[i] += delta;
        nonZeroCount += count[i] > 0;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, typeCount;
    cin >> size >> typeCount;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    Counter counter(typeCount + 1);
    int resL = 0, resR = size - 1;

    for (int l = 0, r = 0; r < size; r++) {
        counter.add(a[r], 1);
        while (counter.nonZeroCount == typeCount) {
            if (resR - resL > r - l) {
                resL = l;
                resR = r;
            }
            counter.add(a[l], -1);
            l++;
        }
    }

    cout << resL + 1 << " " << resR + 1;
}