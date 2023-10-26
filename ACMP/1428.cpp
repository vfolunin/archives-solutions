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

    long long length;
    cin >> length;

    __float128 PI = acosl(-1);
    __float128 radius = length / (2 * PI);

    cout << (long long)radius * 8 + 4;
}