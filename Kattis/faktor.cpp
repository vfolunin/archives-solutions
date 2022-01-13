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

    int articleCount, impact;
    cin >> articleCount >> impact;

    int l = -1, r = articleCount * impact;
    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if ((m + articleCount - 1) / articleCount < impact)
            l = m;
        else
            r = m;
    }

    cout << r;
}