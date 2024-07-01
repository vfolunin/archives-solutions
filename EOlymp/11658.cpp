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
    int l = 0, r = 0;
    for (int &value : a) {
        cin >> value;
        r += value;
    }

    l = a[0];
    r -= a[0];

    int res = 0;
    for (int i = 1; i + 1 < a.size(); i++) {
        r -= a[i];
        res += l == r;
        l += a[i];
    }

    cout << res;
}