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

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long size, to;
    cin >> size >> to;

    if (to_string(to).size() > size)
        to = powerOfTen(size);

    long long from = powerOfTen(size - 1);

    cout << max(to - from, 0LL);
}