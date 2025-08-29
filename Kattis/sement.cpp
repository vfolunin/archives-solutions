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

    int size;
    long long targetSum;
    cin >> size >> targetSum;

    vector<long long> a(size);
    for (long long &value : a)
        cin >> value;

    sort(a.begin(), a.end());

    for (int l = 0, r = a.size() - 1; l < r; l++) {
        while (l < r && a[l] + a[r] > targetSum)
            r--;
        if (l < r && a[l] + a[r] == targetSum) {
            cout << a[l] << " " << a[r];
            return 0;
        }
    }

    cout << "Neibb";
}