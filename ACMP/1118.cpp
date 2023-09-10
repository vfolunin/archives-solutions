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

    int h, a, b;
    cin >> h >> a >> b;

    cout << (max(h - a, 0) + a - b - 1) / (a - b) + 1;
}