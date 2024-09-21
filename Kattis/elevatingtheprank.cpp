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

    int l, r, size;
    cin >> l >> r >> size;

    if (l > r)
        swap(l, r);

    int res = (r - l) * 4;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        res += (l < value && value < r) * 10;
    }

    cout << res;
}