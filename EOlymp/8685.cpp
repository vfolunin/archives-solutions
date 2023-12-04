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

    double num = 0, den = 0;

    for (double value; cin >> value; ) {
        num += value;
        den++;
    }

    cout << fixed << num / den;
}