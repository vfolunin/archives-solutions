#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isGood(int n) {
    return n % 10 == 7 && 100 <= n && n <= 999;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<int> a;
    for (int value; cin >> value; )
        a.push_back(value);

    int limit = -1e9;
    for (int value : a)
        if (abs(value) % 10 == 7)
            limit = max(value, limit);

    int count = 0, maxSum = -1e9;
    for (int i = 0, j = 1; j < a.size(); i++, j++) {
        if (to_string(abs(a[i]))[0] == to_string(abs(a[j]))[0] &&
            (isGood(a[i]) || isGood(a[j])) && a[i] + a[j] < limit) {
            count++;
            maxSum = max(maxSum, a[i] + a[j]);
        }
    }

    cout << count << " " << maxSum;
}