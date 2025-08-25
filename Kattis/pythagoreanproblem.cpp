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

    int a, b;
    cin >> a >> b;

    if (a > b)
        swap(a, b);

    int c = sqrt(b * b - a * a);
    if (c && a * a + c * c == b * b) {
        cout << c;
        return 0;
    }

    c = sqrt(a * a + b * b);
    if (a * a + b * b == c * c) {
        cout << c;
        return 0;
    }

    cout << "Pythagoras is sad :(";
}