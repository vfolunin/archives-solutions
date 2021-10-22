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

    int n;
    cin >> n;

    double res = 0;
    for (int i = 0; i < n; i++)
        res = 1 / (res + 6);

    cout.precision(10);
    cout << fixed << 3 + res << "\n";
}