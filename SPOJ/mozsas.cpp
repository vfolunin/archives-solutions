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

    int size;
    cin >> size;

    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;
    }

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;

        int count = (r - l + 1) / 2 + (l % 2 && r % 2);

        cout << (count % 2 ? "Odd\n" : "Even\n");
    }
}