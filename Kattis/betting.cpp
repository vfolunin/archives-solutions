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

    int p;
    cin >> p;

    cout << fixed << 100.0 / p << "\n";
    cout << fixed << 100.0 / (100.0 - p) << "\n";
}