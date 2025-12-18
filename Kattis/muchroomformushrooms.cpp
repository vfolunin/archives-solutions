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

    if (w == 1)
        cout << 1;
    else if (h == 1)
        cout << (w + 2) / 3;
    else if (h == 2)
        cout << (w + 2) / 2;
    else
        cout << -1;
}