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

    double va, vb, vc;
    cin >> va >> vb >> vc;

    double sa = 0.5, sbc = 0.5;
    double ta = sa / va, tbc = sbc / (vb + vc) * 2;

    cout << fixed << (sa + sbc) / (ta + tbc);
}