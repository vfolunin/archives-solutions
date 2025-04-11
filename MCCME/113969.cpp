#include <iostream>
#include <algorithm>
#include <cmath>
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

    long long r = sqrt(2 * n);
    while (r < 1 || r * (r + 1) / 2 < n)
        r++;

    cout << r * (r + 1) / 2;
}