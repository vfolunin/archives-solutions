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

    int size, threshold;
    cin >> size >> threshold;

    vector<int> a(size);
    int sum = 0;
    for (int &value : a) {
        cin >> value;
        sum += value;
    }

    if (sum < threshold) {
        cout << -1;
        return 0;
    }

    int resStart, resCount = size + 1;
    for (int start = 0; start < size; start++) {
        int count = 0, sum = 0;
        while (sum < threshold) {
            sum += a[(start + count) % a.size()];
            count++;
        }
        if (resCount > count) {
            resStart = start;
            resCount = count;
        }
    }

    cout << resStart + 1 << " " << resCount;
}