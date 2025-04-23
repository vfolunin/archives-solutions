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
 
    double d, h1, h2, l;
    cin >> d >> h1 >> h2 >> l;

    if (h1 > h2)
        swap(h1, h2);

    double h = hypot(d, h2 - h1);
    if (h1 - (h2 - h) > l)
        h = (d * d + l * l) / (2 * l);

    cout << fixed << h1 + min(h2, h);
}