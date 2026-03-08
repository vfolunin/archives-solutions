#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getDivisorSum(int n) {
    int divisorSum = 0;
    for (long long d = 1; d * d <= n; d++) {
        if (n % d == 0) {
            divisorSum += d;
            if (d * d != n)
                divisorSum += n / d;
        }
    }
    return divisorSum;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int value;
    cin >> value;
    value++;

    for (int i = 0; i < 5; value++) {
        int divisorSum = getDivisorSum(value);
        if (divisorSum % 10 == 6) {
            cout << value << " " << divisorSum << "\n";
            i++;
        }
    }
}