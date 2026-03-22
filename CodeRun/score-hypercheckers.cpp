#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getCount(vector<long long> &a, long long l, long long r) {
    return upper_bound(a.begin(), a.end(), r) - lower_bound(a.begin(), a.end(), l);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    long long maxDiff;
    cin >> size >> maxDiff;

    map<long long, int> count;
    for (int i = 0; i < size; i++) {
        long long value;
        cin >> value;
        count[value]++;
    }

    vector<long long> values;
    for (auto &[value, count] : count)
        values.push_back(value);

    long long res = 0;

    for (auto &[value, count] : count) {
        if (count >= 3)
            res++;

        if (count >= 2) {
            int less = getCount(values, (value + maxDiff - 1) / maxDiff, value - 1);
            int greater = getCount(values, value + 1, value * maxDiff);
            res += 3LL * (less + greater);
        }

        int greater = getCount(values, value + 1, value * maxDiff);
        res += 3LL * greater * (greater - 1);
    }

    cout << res;
}