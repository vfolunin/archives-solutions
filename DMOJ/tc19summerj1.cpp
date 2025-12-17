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

    int size, target;
    cin >> size >> target;

    int res = size, resDelta = abs(size - target);

    for (; size; size /= 2) {
        int delta = abs(size - target);
        if (resDelta > delta) {
            res = size;
            resDelta = delta;
        }
    }

    cout << res;
}