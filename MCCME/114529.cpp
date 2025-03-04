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
    long long sl = 0, sr = 0;
    for (int &value : a) {
        cin >> value;
        sr += value;
    }

    long long resDiff = 1e18;
    int res = 0;
    for (int i = 0; i + 1 < size; i++) {
        sl += a[i];
        sr -= a[i];
        if (resDiff > abs(sl - sr)) {
            resDiff = abs(sl - sr);
            res = i + 1;
        }
    }

    cout << res;
}