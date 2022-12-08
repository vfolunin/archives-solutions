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

    int width, legCount;
    cin >> width >> legCount;

    int l = -1, r = width + 1;
    for (int i = 0; i < legCount; i++) {
        int pos;
        cin >> pos;

        if (pos * 2 < width)
            l = max(l, pos);
        if (pos >= width / 2)
            r = min(r, pos);
    }

    cout << l;
    if (l != r)
        cout << " " << r;
}