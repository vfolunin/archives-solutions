#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long getTenFactor(long long value) {
    long long res = 1;
    for (; value; value /= 10)
        res *= 10;
    return res;
}

bool isDivisible(vector<long long> &a, int divisor) {
    long long remainder = 0;
    for (long long value : a)
        remainder = (remainder * getTenFactor(value) + value) % divisor;
    return !remainder;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int divisor, size;
    cin >> divisor >> size;

    vector<long long> a(size);
    for (long long &value : a)
        cin >> value;
    sort(a.begin(), a.end());

    int res = 0;
    do {
        res += isDivisible(a, divisor);
    } while (next_permutation(a.begin(), a.end()));

    cout << res;
}