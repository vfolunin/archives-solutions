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

    int size, segmentCount;
    cin >> size >> segmentCount;

    vector<int> a(size);
    for (int i = 0; i < segmentCount; i++) {
        int l, r;
        cin >> l >> r;

        fill(a.begin() + l - 1, a.begin() + r, 1);
    }

    cout << (count(a.begin(), a.end(), 0) ? "NO" : "YES");
}