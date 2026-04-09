#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("gcd.in", "r", stdin);
    freopen("gcd.out", "w", stdout);

    int a, b;
    cin >> a >> b;

    cout << gcd(a, b);
}