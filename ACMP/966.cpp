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

    int segmentCount;
    cin >> segmentCount;

    vector<int> delta(1001);
    for (int i = 0; i < segmentCount; i++) {
        int l, r, volume;
        cin >> l >> r >> volume;

        delta[l] += volume;
        delta[r] -= volume;
    }

    int time;
    cin >> time;

    long long sum = 0, add = 0;
    for (int i = 0; i < delta.size() && i < time; i++) {
        add += delta[i];
        sum = max(sum + add, 0LL);
    }

    cout << sum;
}