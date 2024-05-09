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

    int size, targetSum;
    cin >> size >> targetSum;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    sort(a.begin(), a.end());

    for (int i = 0; i < a.size(); i++) {
        for (int l = i + 1, r = a.size() - 1; l < r; l++) {
            while (l < r && a[i] + a[l] + a[r] > targetSum)
                r--;

            if (l < r && a[i] + a[l] + a[r] == targetSum) {
                cout << a[i] << " " << a[l] << " " << a[r];
                return 0;
            }
        }
    }

    cout << -1;
}