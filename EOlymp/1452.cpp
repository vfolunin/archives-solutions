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

    int n, k;
    cin >> n >> k;

    int res = 1;
    for (int i = 0; i < n; i++) {
        if (res > k)
            res -= k;
        res *= 2;
    }

    cout << res;
}