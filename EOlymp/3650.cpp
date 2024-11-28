#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    unordered_set<int> sums;
    for (int mask = 1; mask < (1 << a.size()); mask++) {
        int sum = 0;
        for (int bit = 0; bit < size; bit++)
            if (mask & (1 << bit))
                sum += a[bit];
        sums.insert(sum);
    }

    cout << sums.size();
}