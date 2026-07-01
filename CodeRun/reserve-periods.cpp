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
    long long threshold;
    cin >> size >> threshold;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    long long sum = 0, res = 0;
    for (int l = 0, r = 0; r < a.size(); r++) {
        sum += a[r];
        while (sum >= threshold)
            sum -= a[l++];
        res += l;
    }

    cout << res;
}