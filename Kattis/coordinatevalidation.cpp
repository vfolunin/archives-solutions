#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    double lon, lat;
    cin >> lon >> lat;

    cout << (-180 <= lon && lon <= 180 && -90 <= lat && lat <= 90 ? "VALID\n" : "INVALID\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}