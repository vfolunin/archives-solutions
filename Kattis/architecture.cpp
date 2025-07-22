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

    int h, w;
    cin >> h >> w;

    vector<int> r(h);
    for (int &value : r)
        cin >> value;

    vector<int> c(w);
    for (int &value : c)
        cin >> value;

    vector<int> resR(h), resC(w);
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            int value = min(r[y], c[x]);
            resR[y] = max(resR[y], value);
            resC[x] = max(resC[x], value);
        }
    }

    cout << (r == resR && c == resC ? "possible" : "impossible");
}