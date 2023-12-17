#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int h, w;
    cin >> h >> w;

    int g = gcd(h, w);
    h /= g;
    w /= g;

    cout << h + w - 2 << " ";
    if (h % 2 && w % 2)
        cout << 3;
    else if (w % 2)
        cout << 2;
    else
        cout << 4;
}