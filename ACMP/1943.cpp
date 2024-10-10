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

    int h, w;
    cin >> h >> w;

    long long res = 1LL << (h * w - 1);
    res += ((1LL << (w - 1)) - 1) * ((1LL << (h - 1)) - 1) * (1LL << ((h - 1) * (w - 1)));

    cout << res;
}