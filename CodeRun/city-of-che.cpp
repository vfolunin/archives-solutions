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

    int size, minDist;
    cin >> size >> minDist;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    long long pairCount = 0;

    for (int l = 0, r = 0; l < size; l++) {
        while (r < size && a[r] - a[l] <= minDist)
            r++;
        pairCount += size - r;
    }

    cout << pairCount;
}