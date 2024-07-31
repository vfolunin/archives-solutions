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

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    int sum = 0;
    for (int i = 0; i < windowSize; i++)
        sum += a[i];

    int minSum = sum, maxSum = sum;
    for (int l = 0, r = windowSize; r < a.size(); l++, r++) {
        sum += a[r] - a[l];
        minSum = min(minSum, sum);
        maxSum = max(maxSum, sum);
    }

    cout.precision(0);
    cout << fixed << (double)minSum / windowSize << "\n";
    cout << fixed << (double)maxSum / windowSize;
}