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

    double f;
    cin >> f;

    cout.precision(0);
    cout << fixed << (f - 32) * 5 / 9;
}