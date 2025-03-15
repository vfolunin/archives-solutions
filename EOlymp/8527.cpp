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

    double a, b;
    cin >> a >> b;

    if (!a)
        cout << (0 <= b ? "all" : "no solution");
    else if (a > 0)
        cout << "-INF " << floor(b / a);
    else
        cout << ceil(b / a) << " INF";
}