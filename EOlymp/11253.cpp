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

    int size, couponCount;
    cin >> size >> couponCount;

    multiset<int> values;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;
        values.insert(value);
    }

    for (int i = 0; i < couponCount; i++) {
        int value = *prev(values.end());
        values.erase(prev(values.end()));
        values.insert(value / 2);
    }

    long long res = 0;
    for (int value : values)
        res += value;

    cout << res;
}