#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

struct Counter {
    unordered_map<int, int> count;
    int nonzero = 0;

    void add(int value, int delta) {
        nonzero -= count[value] != 0;
        count[value] += delta;
        nonzero += count[value] != 0;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    vector<int> b = a;
    sort(b.begin(), b.end());

    Counter counter;
    int res = 0;

    for (int i = 0; i < a.size(); i++) {
        counter.add(a[i], 1);
        counter.add(b[i], -1);
        res += !counter.nonzero;
    }

    cout << res;
}