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

    int a = 0, b = 0, c = 0, res = 0;

    while (1) {
        cin >> c;

        if (!c)
            break;

        res += a && b && a < b && b > c;
        a = b;
        b = c;
    }

    cout << res;
}