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

    int size, count;
    cin >> size >> count;

    vector<long long> a(size);
    for (long long &value : a)
        cin >> value;

    sort(a.begin(), a.end());

    long long res = 0;
    for (int i = 0; i < a.size(); i++) {
        if (i >= count)
            a[i] += a[i - count];
        res += a[i];
    }

    cout << res;
}