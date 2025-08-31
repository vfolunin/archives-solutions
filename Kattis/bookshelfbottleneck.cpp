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

    int size, limit;
    cin >> size >> limit;

    long long res = 0;
    for (int i = 0; i < size; i++) {
        vector<int> a(3);
        for (int &value : a)
            cin >> value;

        sort(a.begin(), a.end());

        if (a[1] <= limit) {
            res += a[0];
        } else if (a[0] <= limit) {
            res += a[1];
        } else {
            cout << "impossible";
            return 0;
        }
    }

    cout << res;
}