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

    int size, multiple;
    cin >> size >> multiple;

    int res = 1e9;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (multiple % value == 0)
            res = min(res, multiple / value);
    }

    cout << res;
}