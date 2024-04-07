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

    double x, k;
    cin >> x >> k;

    double a = pow(x, 2) + pow(k, 3);

    cout << fixed << pow(log10(a), 3) + pow(cos(x), 5);
}