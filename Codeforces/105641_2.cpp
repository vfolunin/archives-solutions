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

    long long h, w;
    cin >> h >> w;

    cout << h * w * 8 + (h - 1) * w * 2 + h * (w - 1) * 2 + (h - 1) * (w - 1) * 4;
}