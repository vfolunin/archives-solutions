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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}