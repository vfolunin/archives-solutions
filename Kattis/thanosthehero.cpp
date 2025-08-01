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

    vector<long long> a(size);
    for (long long &value : a)
        cin >> value;

    long long res = 0;
    for (int i = a.size() - 2; i >= 0; i--) {
        long long target = min(a[i], a[i + 1] - 1);
        if (target < 0) {
            cout << 1;
            return 0;
        }

        res += a[i] - target;
        a[i] = target;
    }

    cout << res;
}