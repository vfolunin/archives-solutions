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

    int res = 7;
    n = max(0, n - 10);

    res += min(n, 20);
    n = max(0, n - 20);

    res += min(n, 70) * 2;
    n = max(0, n - 70);

    res += n * 5;
    cout << res << "\n";
}