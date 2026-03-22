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

    vector<int> a(10);
    for (int &value : a)
        cin >> value;

    int res = 0;
    for (int mask = 0; mask < (1 << a.size()); mask++) {
        int sum = 0;
        for (int bit = 0; bit < a.size(); bit++)
            if (mask & (1 << bit))
                sum += a[bit];
        
        if (abs(res - 100) > abs(sum - 100) || abs(res - 100) == abs(sum - 100) && res < sum)
            res = sum;
    }

    cout << res;
}