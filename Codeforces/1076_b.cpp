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

    long long n;
    cin >> n;

    long long d = 2;
    while (d * d <= n && n % d)
        d++;
    if (n % d)
        d = n;

    cout << 1 + (n - d) / 2;
}