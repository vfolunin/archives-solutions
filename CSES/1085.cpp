#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(vector<int> &a, long long partSum, int partCount) {
    int parts = 1;
    long long sum = 0;
    for (int x : a) {
        if (sum + x <= partSum) {
            sum += x;
        } else {
            sum = x;
            parts++;
        }
    }
    return parts <= partCount;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, partCount;
    cin >> size >> partCount;

    vector<int> a(size);
    for (int &x : a)
        cin >> x;

    long long l = *max_element(a.begin(), a.end()) - 1, r = 1LL << 60;
    while (l + 1 < r) {
        long long m = l + (r - l) / 2;
        if (can(a, m, partCount))
            r = m;
        else
            l = m;
    }

    cout << r;
}