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

    long long h, w, border;
    cin >> h >> w >> border;

    cout << h * w - (h - 2 * border) * (w - 2 * border);
}