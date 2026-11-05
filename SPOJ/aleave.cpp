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

    int segmentCount;
    cin >> segmentCount;

    vector<int> used(400);
    for (int i = 0; i < segmentCount; i++) {
        int l, r;
        cin >> l >> r;

        fill(used.begin() + l, used.begin() + r, 1);
    }

    cout << count(used.begin(), used.end(), 1);
}