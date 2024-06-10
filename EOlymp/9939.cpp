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

    long long size, from;
    cin >> size >> from;

    if (to_string(from).size() < size)
        from = powerOfTen(size - 1);

    long long to = powerOfTen(size);

    cout << max(to - from, 0LL);
}