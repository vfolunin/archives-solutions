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
    cin >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    int res = 0;
    for (int l = 0; l < size; l++) {
        int sum = 0;
        for (int r = l; r < size; r++) {
            sum += a[r];
            for (int i = l; i <= r; i++) {
                if (a[i] * (r - l + 1) == sum) {
                    res++;
                    break;
                }
            }
        }
    }

    cout << res;
}