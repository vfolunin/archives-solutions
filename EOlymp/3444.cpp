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

    if (h > w)
        swap(h, w);

    if (h == 1)
        cout << w;
    else
        cout << (h + w - 2) * 2;
}