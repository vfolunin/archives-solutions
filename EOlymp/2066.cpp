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

    int n;
    cin >> n;

    cout.precision(3);
    cout << fixed << n * (n - 1.0) << " " << sqrt(3) / 2 * (2 * n - 1);
}