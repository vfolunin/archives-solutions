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

    int segmentCount, threshold;
    cin >> segmentCount >> threshold;

    vector<int> count(24);
    for (int i = 0; i < segmentCount; i++) {
        int l, r;
        cin >> l >> r;

        for (int j = l; j < r; j++)
            count[j]++;
    }

    int res = 0;
    for (int count : count)
        res += count >= threshold;

    cout << res;
}