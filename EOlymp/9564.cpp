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

    vector<int> rowSum(h);
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            int value;
            cin >> value;
            rowSum[y] += value;
        }
    }

    int maxSum = *max_element(rowSum.begin(), rowSum.end());

    for (int y = 0; y < h; y++)
        if (rowSum[y] == maxSum)
            cout << y + 1 << " ";
}