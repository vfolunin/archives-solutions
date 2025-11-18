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

    int res = 0;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        res += l <= value && value <= r;
    }

    cout << res;
}