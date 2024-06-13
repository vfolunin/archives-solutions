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

    double d;
    cin >> d;

    cout << fixed << (1 + 1 / d) / (1 - 1 / d);
}