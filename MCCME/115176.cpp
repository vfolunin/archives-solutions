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
    if (h > w)
        swap(h, w);

    cout << (h - 1) * 3 + w - 1 - (h == w && h % 2 == 0);
}