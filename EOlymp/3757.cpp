#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int read() {
    double value;
    cin >> value;
    return round(value * 100);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int a = read(), b = read(), c = read();

    cout << (a + b) / c;
}