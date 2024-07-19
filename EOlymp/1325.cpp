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

    int size, l, r;
    cin >> size >> l >> r;

    if (l > r)
        swap(l, r);

    long long res = 1;
    for (int i = 1; i <= size; i++) {
        int count;
        cin >> count;

        if (l <= i && i <= r)
            res *= count;
    }

    cout << res;
}