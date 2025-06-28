#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, windowSize;
    cin >> size >> windowSize;

    vector<int> a(size);
    long long b, c;
    int mod;
    cin >> a[0] >> b >> c >> mod;

    for (int i = 1; i < size; i++)
        a[i] = (a[i - 1] * b + c) % mod;

    deque<int> values, minimums;
    for (int i = 0; i < windowSize; i++) {
        values.push_back(a[i]);
        while (!minimums.empty() && a[i] < minimums.back())
            minimums.pop_back();
        minimums.push_back(a[i]);
    }

    int res = minimums.front();
    for (int i = windowSize; i < size; i++) {
        if (minimums.front() == values.front())
            minimums.pop_front();
        values.pop_front();

        values.push_back(a[i]);
        while (!minimums.empty() && a[i] < minimums.back())
            minimums.pop_back();
        minimums.push_back(a[i]);

        res ^= minimums.front();
    }

    cout << res;
}