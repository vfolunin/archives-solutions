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

    int prev, cur = -1;

    while (1) {
        prev = cur;
        if (!(cin >> cur) || cur <= prev)
            break;
    }

    cout << prev + 1 << "\n";
}