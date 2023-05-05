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

    long long n, p;
    cin >> n >> p;

    if (n > 1)
        while (p % n == 0)
            p /= n;

    cout << (p == 1 ? "YES" : "NO");
}