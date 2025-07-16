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

    double x;
    for (int i = 0; i < 12; i++)
        cin >> x;

    cout << fixed << x * x / acos(-1) / exp(1) + 1 / (x + 1);
}