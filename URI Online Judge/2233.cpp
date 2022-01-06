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

    long long r, g, b;
    cin >> hex >> r >> g >> b;

    long long rg = (r / g) * (r / g);
    long long gb = (g / b) * (g / b);

    cout << hex << 1 + rg + rg * gb << "\n";
}