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

    double a, b, c;
    cin >> a >> b >> c;

    if (a == b) {
        cout << -1;
    } else {
        cout.precision(1);
        cout << fixed << (c - b) / (a - b) * 1000;
    }
}