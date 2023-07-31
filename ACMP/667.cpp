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

    int a, b, capacity;
    cin >> a >> b >> capacity;

    if (capacity <= 2) {
        cout << 0;
        return 0;
    }

    int res = (a + capacity - 3) / (capacity - 2);

    if (b >= res * 2) {
        res = (a + b + capacity - 1) / capacity;
        cout << res;
    } else {
        cout << 0;
    }
}