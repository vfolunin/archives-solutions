#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long getCount(long long l, long long r) {
    if (l > r)
        return 0;
    return (r - l + 1) / 2 + (l % 2 && r % 2);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    long long l, r;
    cin >> size >> l >> r;
    if (l > r)
        swap(l, r);

    long long from = 1;
    for (int i = 0; i < size - 1; i++)
        from *= 10;

    long long to = from * 10 - 1;

    cout << getCount(max(from, l), min(to, r));
}