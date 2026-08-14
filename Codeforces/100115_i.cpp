#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("treasure.in", "r", stdin);
    freopen("treasure.out", "w", stdout);

    int a, b;
    cin >> a >> b;

    cout << gcd(a, b);
}