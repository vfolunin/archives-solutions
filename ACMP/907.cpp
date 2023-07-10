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

    int h, w, r;
    cin >> h >> w >> r;

    cout << (2 * r <= min(h, w) ? "YES" : "NO");
}