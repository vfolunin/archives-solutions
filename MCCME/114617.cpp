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

    int res = 0;
    while (h && w) {
        if (h < w)
            swap(h, w);
        res += h / w;
        h %= w;
    }

    cout << res;
}