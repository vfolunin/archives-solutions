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

    int a, b;
    cin >> a >> b;

    for (int h = 1; h <= 1001; h++) {
        for (int w = 1; w <= 1001; w++) {
            if (h * w - h - w + 1 == a && 2 * h * w - h - w == b) {
                cout << h << " " << w;
                return 0;
            }
        }
    }
}