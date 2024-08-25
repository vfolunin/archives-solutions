#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long a, b;
    cin >> a >> b;

    if (gcd(a, b) == 1)
        cout << a * b - a - b << " " << (a - 1) * (b - 1) / 2;
    else
        cout << "NA";
}