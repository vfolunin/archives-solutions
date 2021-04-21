#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    long long height, width;
    cin >> height >> width;

    if (!height && !width)
        return 0;

    if (height > width)
        swap(height, width);

    long long res = width * (height - 1) * height;
    res += (width - 1) * width * height;
    res += 4 * (height - 2) * (height - 1) * height / 3;
    res += 2 * (height - 1) * height * (width - height + 1);

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}