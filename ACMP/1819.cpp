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

    int size;
    cin >> size;

    long long sum = 0;
    map<long long, int> seen = { { sum, -1 } };
    int res = 0;

    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        sum += value;

        if (seen.count(sum))
            res = max(res, i - seen[sum]);
        else
            seen[sum] = i;
    }

    cout << res;
}