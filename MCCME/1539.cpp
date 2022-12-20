#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getDivisorSum(int n) {
    int sum = 0;
    for (long long d = 1; d * d <= n; d++) {
        if (n % d == 0) {
            sum += d;
            if (d * d != n)
                sum += n / d;
        }
    }
    return sum;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    int res, resSum = 0;
    for (int i = 1; i <= n; i++) {
        int sum = getDivisorSum(i);
        if (resSum < sum) {
            res = i;
            resSum = sum;
        }
    }

    cout << res;
}