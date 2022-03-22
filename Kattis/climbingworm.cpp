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

    int a, b, h;
    cin >> a >> b >> h;

    h = max(h - a, 0);

    cout << (h + a - b - 1) / (a - b) + 1;
}