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

    int size, windowSize;
    cin >> size >> windowSize;

    windowSize = min(1 + windowSize / 3 * 2, size);

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    long long sum = 0;
    for (int i = 0; i < windowSize; i++)
        sum += a[i];

    long long res = sum;
    for (int i = windowSize; i < size; i++) {
        sum += a[i] - a[i - windowSize];
        res = max(res, sum);
    }

    cout << res;
}