#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isGood(int value) {
    int oddCount = 0;
    for (; value; value /= 10) {
        if (value % 10 == 0)
            return 0;
        oddCount += value % 10 % 2;
    }
    return oddCount == 2;
}

int transform(int value) {
    vector<int> sum(2);
    for (; value; value /= 10)
        sum[value % 10 % 2] += value % 10;
    return sum[0] * (sum[1] > 9 ? 100 : 10) + sum[1];
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int value;
    cin >> value;

    int res = 1000;
    while (!isGood(res) || transform(res) != value)
        res++;

    cout << res;
}