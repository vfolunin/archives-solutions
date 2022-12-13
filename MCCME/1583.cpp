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

    int size, windowSize, targetSum;
    cin >> size >> windowSize >> targetSum;
    windowSize++;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    int windowSum = 0;
    for (int i = 0; i < windowSize; i++)
        windowSum += a[i];

    if (windowSum == targetSum) {
        cout << 1;
        return 0;
    }

    for (int i = windowSize; i < size; i++) {
        windowSum -= a[i - windowSize];
        windowSum += a[i];

        if (windowSum == targetSum) {
            cout << i - windowSize + 2;
            return 0;
        }
    }

    cout << 0;
}