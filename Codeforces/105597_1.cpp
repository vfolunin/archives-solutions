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

    int h, w, r, c;
    cin >> h >> w >> r >> c;

    cout << h * w - (r * w + c * h - r * c);
}