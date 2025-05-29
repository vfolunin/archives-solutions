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

    vector<int> pos, neg, zero;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (value > 0)
            pos.push_back(value);
        else if (value < 0)
            neg.push_back(value);
        else
            zero.push_back(value);
    }

    long long res = 0;
    if (pos.size() == size) {
        for (int value : pos)
            res += value;
        res -= 2 * *min_element(pos.begin(), pos.end());
    } else if (neg.size() == size) {
        for (int value : neg)
            res -= value;
        res += 2 * *max_element(neg.begin(), neg.end());
    } else {
        for (int value : pos)
            res += value;
        for (int value : neg)
            res -= value;
    }
    cout << res;
}