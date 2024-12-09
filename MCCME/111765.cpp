#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long getSquareSum(vector<long long> &a) {
    sort(a.begin(), a.end());

    long long lSum = 0, lSquareSum = 0, res = 0;
    for (int i = 0; i < a.size(); i++) {
        res += i * a[i] * a[i] - 2 * lSum * a[i] + lSquareSum;
        lSum += a[i];
        lSquareSum += a[i] * a[i];
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<long long> x(size), y(size);
    for (int i = 0; i < size; i++)
        cin >> x[i] >> y[i];

    cout << getSquareSum(x) + getSquareSum(y);
}