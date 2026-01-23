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

    double value;
    cin >> value;

    for (double i = 6, p = (1 << 6); i >= -32; i--, p /= 2) {
        if (value >= p) {
            cout << 1;
            value -= p;
        } else {
            cout << 0;
        }
        if (!i)
            cout << ".";
    }
}