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

    int size, sumLimit;
    cin >> size >> sumLimit;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    int maxTaken = 0;
    for (int l = 0; l < size; l++) {
        int takenSum = 0, taken = 0;
        for (int r = l; r < size; r++) {
            if (takenSum + a[r] <= sumLimit) {
                takenSum += a[r];
                taken++;
            }
        }
        maxTaken = max(maxTaken, taken);
    }

    cout << maxTaken;
}