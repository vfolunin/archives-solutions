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

    vector<long long> a;
    for (long long value; cin >> value; )
        a.push_back(value);

    long long threshold = -1e18;
    for (long long value : a)
        if (abs(value) % 100 == 42)
            threshold = max(threshold, value);
    threshold *= threshold;

    int count = 0;
    long long maxProduct = -1e18;
    for (int i = 0; i + 2 < a.size(); i++) {
        if ((abs(a[i]) % 100 == 42) + (abs(a[i + 1]) % 100 == 42) + (abs(a[i + 2]) % 100 == 42) >= 2 &&
            a[i] * a[i + 1] * a[i + 2] > threshold) {
            count++;
            maxProduct = max(maxProduct, a[i] * a[i + 1] * a[i + 2]);
        }
    }

    cout << count << " " << maxProduct;
}