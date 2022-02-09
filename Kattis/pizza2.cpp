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

    double totalR, outerR;
    cin >> totalR >> outerR;

    double innerR = totalR - outerR;

    cout << fixed << 100 * innerR * innerR / totalR / totalR;
}