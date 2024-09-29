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

    int a, b;
    cin >> a >> b;

    a *= 2;
    b *= 2;

    if (b < a / 2) {
        cout << "up";
        return 0;
    }

    b -= a / 2;
    b %= a * 2;

    cout << (b < a ? "down" : "up");
}