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

    int h, w;
    cin >> h >> w;

    if (2 * sqrt(h * w / (2 * 3.14159265)) <= min(h, w) + 1e-9)
        cout << "circle";
    else if (sqrt(h * w / 2) <= min(h, w) + 1e-9)
        cout << "square";
    else
        cout << "blank";
}