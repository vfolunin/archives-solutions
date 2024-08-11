#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long powerOfTen(int p) {
    long long res = 1;
    for (int i = 0; i < p; i++)
        res *= 10;
    return res;
}

long long lessCount(int size, long long to) {
    if (to_string(to).size() > size)
        to = powerOfTen(size);

    long long from = powerOfTen(size - 1);

    return max(to - from, 0LL);
}

long long greaterCount(int size, long long from) {
    if (to_string(from).size() < size)
        from = powerOfTen(size - 1);
    else
        from++;

    long long to = powerOfTen(size);

    return max(to - from, 0LL);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long size, l, r;
    cin >> size >> l >> r;

    cout << lessCount(size, l) + greaterCount(size, r);
}