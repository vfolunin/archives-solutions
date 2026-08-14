#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    long long value;
    cin >> value;

    long long root = sqrt(value);

    cout << (root * root == value) << " ";
}

int main() {
    freopen("veryhard.in", "r", stdin);
    freopen("veryhard.out", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}