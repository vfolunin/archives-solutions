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

    vector<int> values = {
        1, 64, 729, 4096, 15625,
        46656, 117649, 262144, 531441, 1000000,
        1771561, 2985984, 4826809, 7529536, 11390625,
        16777216, 24137569, 34012224, 47045881, 64000000, 85766121
    };

    int l, r;
    cin >> l >> r;

    int res = 0;
    for (int value : values)
        res += l <= value && value <= r;

    cout << res;
}