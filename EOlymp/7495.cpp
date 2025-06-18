#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int digitSum(int n) {
    int sum = 0;
    while (n) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int targetCount;
    cin >> targetCount;

    unordered_map<int, int> count;
    unordered_map<int, long long> sum;

    for (int value = 1; value <= 1e6; value++) {
        int valueSum = digitSum(value);
        if (count[valueSum] < targetCount) {
            count[valueSum]++;
            sum[valueSum] += value;
        }
    }

    long long res = 1e18;
    for (auto &[valueSum, count] : count)
        if (count == targetCount)
            res = min(res, sum[valueSum]);

    cout << res;
}