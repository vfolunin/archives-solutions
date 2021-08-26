#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    long long capacity, weight1, value1, weight2, value2;
    cin >> capacity >> weight1 >> value1 >> weight2 >> value2;

    if (weight1 > weight2) {
        swap(weight1, weight2);
        swap(value1, value2);
    }

    long long res = 0;
    
    cout << "Case #" << test << ": ";

    if (weight2 * weight2 >= capacity) {
        for (long long count2 = 0; count2 * weight2 <= capacity; count2++)
            res = max(res, (capacity - count2 * weight2) / weight1 * value1 + count2 * value2);

        cout << res << "\n";
        return;
    }

    if (value1 * weight2 > value2 * weight1) {
        swap(weight1, weight2);
        swap(value1, value2);
    }

    for (long long count1 = 0; count1 <= weight2; count1++)
        res = max(res, count1 * value1 + (capacity - count1 * weight1) / weight2 * value2);

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}