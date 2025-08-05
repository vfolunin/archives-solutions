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

    vector<long long> a(size);
    for (long long &value : a) {
        long long x, y;
        cin >> x >> y;

        value = x * x + y * y;
    }

    sort(a.begin(), a.end());

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        long long r;
        cin >> r;

        cout << upper_bound(a.begin(), a.end(), r * r) - a.begin() << "\n";
    }
}