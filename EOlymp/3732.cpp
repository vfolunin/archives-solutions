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

    int res = 0, delta = 1;
    for (int i = 1; i <= n; i++) {
        delta *= i;
        res += delta;
    }

    cout << res;
}