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

    int l, r;
    cin >> l >> r;
    l--;

    int lSize = l * log10(2) + 1;
    int rSize = r * log10(2) + 1;

    cout << rSize - lSize;
}