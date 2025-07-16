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

    if (h % 2 == 0)
        cout << 0;
    else if (w % 2)
        cout << 1;
    else if (h < w)
        cout << 2;
    else
        cout << 0;
}