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

    long long root = sqrt(2 * n);

    if (root * (root + 1) / 2 == n)
        cout << root;
    else
        cout << -1;
}