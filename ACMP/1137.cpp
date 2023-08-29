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

    int prevValue, value = 1e9, res = 0;

    while (1) {
        prevValue = value;
        cin >> value;

        if (!value)
            break;

        res += prevValue < value;
    }

    cout << res;
}