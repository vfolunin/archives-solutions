#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int transform(int value) {
    vector<int> used(10);
    int sum1 = 0, sum2 = 0;

    for (int i = 0; value; i++, value /= 10) {
        int digit = value % 10;
        
        if (used[digit])
            return -1;
        used[digit] = 1;

        if (i % 2 == 0)
            sum1 += digit;

        if (digit == 2 || digit == 3 || digit == 5 || digit == 7)
            sum2 += digit * digit;
    }

    sum1 *= sum1;
    return abs(sum1 - sum2);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int value;
    cin >> value;

    int res = 1e6 - 1;
    while (transform(res) != value)
        res--;

    cout << res;
}