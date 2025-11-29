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

    int swapCount;
    cin >> swapCount;

    vector<int> a(5);
    a[2] = 1;

    for (int i = 0; i < swapCount; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;

        swap(a[l], a[r]);
    }

    cout << find(a.begin(), a.end(), 1) - a.begin() + 1;
}