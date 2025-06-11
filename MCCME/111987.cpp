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

    vector<long long> rowSum(2);
    for (int y = 0; y < h; y++) {
        int value;
        cin >> value;

        rowSum[y % 2] += value;
    }

    vector<long long> colSum(2);
    for (int x = 0; x < w; x++) {
        int value;
        cin >> value;

        colSum[x % 2] += value;
    }

    cout << rowSum[0] * colSum[0] + rowSum[1] * colSum[1] << " ";
    cout << rowSum[0] * colSum[1] + rowSum[1] * colSum[0];
}