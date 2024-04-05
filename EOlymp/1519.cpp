#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int grayCode(int size, int index) {
    if (!size)
        return 0;

    int half = 1 << (size - 1);
    if (index < half)
        return grayCode(size - 1, index);
    else
        return half + grayCode(size - 1, half - 1 - (index - half));
}

void solve() {
    int size, index;
    cin >> size >> index;

    cout << grayCode(size, index) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}