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

    if (n == 1) {
        cout << 4;
        return 0;
    }

    long long res = 9 * 5;
    for (int i = 0; i < n - 2; i++)
        res *= 10;

    cout << res;
}