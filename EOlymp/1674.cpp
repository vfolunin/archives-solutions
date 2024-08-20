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

    int l, r, value, queryCount;
    cin >> l >> r >> value >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        int delta;
        cin >> delta;

        value = clamp(value + delta, l, r);
    }

    cout << value;
}