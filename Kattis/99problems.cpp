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

    int n;
    cin >> n;

    if (n <= 99) {
        cout << 99;
        return 0;
    }

    int r = n / 100 * 100 + 99;
    int l = r - 100;

    cout << (n - l < r - n ? l : r);
}