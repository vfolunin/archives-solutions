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

    int r;
    cin >> r;

    cout << fixed << acos(-1) * r * r << "\n" << 2 * r * r;
}