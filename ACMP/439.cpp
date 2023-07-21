#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, p;
    cin >> n >> p;

    cout << fixed << 100.0 * n / (100 + (n - 1) * p);
}