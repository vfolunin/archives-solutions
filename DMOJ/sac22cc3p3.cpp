#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
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

    int iterCount = 0;
    for (int value : a)
        iterCount = max<int>(iterCount, to_string(value).size());

    long long mod = 10;
    for (int i = 0; i < iterCount; i++, mod *= 10) {
        stable_sort(a.begin(), a.end(), [&](int lhs, int rhs) {
            return lhs % mod < rhs % mod;
        });

        for (int j = 0; j < a.size(); j++)
            cout << a[j] << (j + 1 < a.size() ? " " : "\n");
    }
}