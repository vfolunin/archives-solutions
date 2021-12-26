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

    int bestSum = 1e9, bestRow = -1;

    for (int i = 0; i < h; i++) {
        int sum = 0;
        for (int j = 0; j < w; j++) {
            int x;
            cin >> x;
            sum += x;
        }
        if (bestSum > sum) {
            bestSum = sum;
            bestRow = i;
        }
    }

    cout << bestRow + 1 << "\n";
}