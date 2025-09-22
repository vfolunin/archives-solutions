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
    while (1) {
        int maxValue = *max_element(a.begin(), a.end());
        if (!maxValue)
            break;

        res = max(res, res ^ maxValue);

        for (int &value : a)
            value = min(value, value ^ maxValue);
    }
    
    cout << res;
}