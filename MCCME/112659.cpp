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

    double a, b, c;
    cin >> a >> b >> c;

    b = c - b;

    if (!a && !b)
        cout << "INFINITY";
    else if (!a)
        cout << "NO";
    else
        cout << (long long)floor(b / a);
}