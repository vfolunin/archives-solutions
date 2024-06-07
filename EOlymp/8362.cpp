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

    long long res = 1;
    while (res * 2 <= n)
        res *= 2;

    if (res >= 2 && res / 2 * 3 <= n)
        res = res / 2 * 3;

    cout << res;
}