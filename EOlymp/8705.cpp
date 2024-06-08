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

    int size, h1, w1, h2, w2;
    cin >> size >> h1 >> w1 >> h2 >> w2;
    if (h1 > w1)
        swap(h1, w1);
    if (h2 > w2)
        swap(h2, w2);

    int res = 0;
    for (int i = 0; i < size; i++) {
        int h, w;
        cin >> h >> w;
        if (h > w)
            swap(h, w);

        res += h <= h1 && w <= w1 || h <= h2 && w <= w2;
    }

    cout << res;
}