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

    double a, g, ra, rg;
    cin >> a >> g >> ra >> rg;

    cout << (a * rg < g * ra ? "A\n" : "G\n");
}