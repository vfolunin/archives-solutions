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

    int h, m, s;
    cin >> h >> m >> s;

    int t = (h * 3600 + m * 60 + s) % (12 * 3600);

    cout.precision(6);
    cout << fixed << t / 120.0;
}