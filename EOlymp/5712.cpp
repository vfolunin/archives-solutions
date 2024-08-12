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

    int res = 0;
    for (; a || b; a /= 2, b /= 2)
        res += a % 2 != b % 2;

    cout << res;
}