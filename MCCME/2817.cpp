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

    int aSize;
    cin >> aSize;

    vector<int> a(aSize);
    for (int &value : a)
        cin >> value;
    sort(a.begin(), a.end());

    int bSize;
    cin >> bSize;

    vector<int> b(bSize);
    for (int &value : b)
        cin >> value;
    sort(b.begin(), b.end());

    int cSize;
    cin >> cSize;

    vector<int> c(cSize);
    for (int &value : c)
        cin >> value;
    sort(c.begin(), c.end());

    int dSize;
    cin >> dSize;

    vector<int> d(dSize);
    for (int &value : d)
        cin >> value;
    sort(d.begin(), d.end());

    int resDiff = 2e9, resAi, resBi, resCi, resDi;

    for (int ai = 0, bi = 0, ci = 0, di = 0; ai < aSize && bi < bSize && ci < cSize && di < dSize; ) {
        int maxValue = max({ a[ai], b[bi], c[ci], d[di] });
        int minValue = min({ a[ai], b[bi], c[ci], d[di] });
        int diff = maxValue - minValue;

        if (diff < resDiff) {
            resDiff = diff;
            resAi = ai;
            resBi = bi;
            resCi = ci;
            resDi = di;
        }

        if (a[ai] == minValue)
            ai++;
        else if (b[bi] == minValue)
            bi++;
        else if (c[ci] == minValue)
            ci++;
        else
            di++;
    }

    cout << a[resAi] << " " << b[resBi] << " " << c[resCi] << " " << d[resDi];
}