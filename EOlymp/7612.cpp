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

    double h, w;
    cin >> h >> w;

    if (h > w)
        swap(h, w);

    cout << fixed << max(min(h / 2, w / 2), min(h, w / 3));
}