#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<long long> a(size);
    long long den = 1;
    for (long long &value : a) {
        cin >> value;
        den = lcm(den, value);
    }

    long long num = 0;
    for (long long value : a)
        num += den / value;

    cout << (num >= den ? "YES" : "NO");
}