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

    int d = 2;
    while (d * d <= n && n % d)
        d++;

    if (n % d == 0)
        cout << n / d << " " << n - n / d;
    else
        cout << 1 << " " << n - 1;
}