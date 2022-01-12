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

    int size, y, x;
    cin >> size >> y >> x;

    cout << 4 * max(y, size - y) * max(x, size - x);
}