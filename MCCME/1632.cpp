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
    cin >> segmentCount >> segmentCount;

    vector<int> l(segmentCount), r(segmentCount);
    for (int i = 0; i < segmentCount; i++)
        cin >> l[i] >> r[i];

    int res = 0;
    for (int i = 0; i < segmentCount; i++) {
        int ok = 1;
        for (int j = i + 1; ok && j < segmentCount; j++)
            ok &= r[i] < l[j] || r[j] < l[i];
        res += ok;
    }

    cout << res;
}