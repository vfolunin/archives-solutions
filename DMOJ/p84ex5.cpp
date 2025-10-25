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

    double a, b;
    cin >> a >> b;

    cout.precision(2);
    if (a)
        cout << fixed << -b / a;
    else if (b)
        cout << "undefined";
    else
        cout << "indeterminate";
}