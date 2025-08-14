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

    double diameter, width;
    int count;
    cin >> diameter >> width >> count;

    cout << (acos(-1) * diameter >= width * count ? "YES" : "NO");
}