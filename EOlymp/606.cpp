#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getDiff(int a, int b) {
    int res = 0;
    for (int i = 0; i < 4; i++) {
        res += a % 10 != b % 10;
        a /= 10;
        b /= 10;
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    int res = 0;
    for (; n < 9999; n++)
        res += getDiff(n, n + 1);

    cout << res;
}