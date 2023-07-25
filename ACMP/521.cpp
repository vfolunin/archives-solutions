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

    int l, r;
    cin >> l >> r;

    int res = 0;
    for (int i = l; i <= r; i++) {
        for (int value = i; value != 2; res++) {
            if (value % 2)
                value = 3 * value + 1;
            else
                value /= 2;
        }
    }

    cout << res;
}