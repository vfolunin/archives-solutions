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

    int size, dy, dx;
    cin >> size >> dy >> dx;

    int res = 0;
    for (int y = 0; y < size; y++)
        for (int x = 0; x < size; x++)
            res += abs(y - size / 2) >= dy && abs(x - size / 2) >= dx;

    cout << max(res - 1, 0);
}