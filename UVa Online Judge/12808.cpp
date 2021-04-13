#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    double poolLength, edgeLength, height, velocity;
    cin >> poolLength >> edgeLength >> height >> velocity;

    double time = sqrt(2 * height / 9810);
    double coord = velocity * time;

    if (coord < edgeLength - 500 || edgeLength + poolLength + 500 < coord)
        cout << "FLOOR\n";
    else if (coord < edgeLength + 500 || edgeLength + poolLength - 500 < coord)
        cout << "EDGE\n";
    else
        cout << "POOL\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}