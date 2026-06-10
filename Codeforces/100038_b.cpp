#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("cinema.in", "r", stdin);
    freopen("cinema.out", "w", stdout);

    long long h, w;
    cin >> h >> w;

    cout << gcd(h - 1, w - 1) + 1;
}