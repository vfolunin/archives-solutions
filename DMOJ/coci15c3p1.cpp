#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int power(int x, int p) {
    int res = 1;
    for (int i = 0; i < p; i++)
        res *= x;
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    int res = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        res += power(x / 10, x % 10);
    }

    cout << res;
}