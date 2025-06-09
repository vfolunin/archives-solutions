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

    int value, size;
    cin >> value >> size;

    int res = value, resIndex = 0;
    for (int i = 1; i <= size; i++) {
        if (value % 2)
            value = 3 * value + 1;
        else
            value /= 2;

        if (res % 1000 <= value % 1000) {
            res = value;
            resIndex = i;
        }
    }

    cout << res << " " << resIndex;
}