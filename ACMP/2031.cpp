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

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int size, threshold;
    cin >> size >> threshold;

    vector<long long> a(size);
    long long sum = 0;
    for (long long &value : a) {
        cin >> value;
        
        if (value >= threshold)
            sum += value;
    }

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        int index, delta;
        cin >> index >> delta;
        index--;

        if (a[index] >= threshold)
            sum -= a[index];
        a[index] += delta;
        if (a[index] >= threshold)
            sum += a[index];

        cout << sum << "\n";
    }
}