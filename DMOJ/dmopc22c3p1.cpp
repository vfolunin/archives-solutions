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

    if (h % 2 && w % 2)
        cout << h * (w + 1) / 2 << " " << h * (w - 1) / 2;
    else
        cout << h * w / 2 << " " << h * w / 2;
}