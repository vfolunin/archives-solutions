#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("chaos.in", "r", stdin);
    freopen("chaos.out", "w", stdout);

    long long count, factor, delta, limit, dayCount;
    cin >> count >> factor >> delta >> limit >> dayCount;

    for (int i = 0; i < dayCount && i < 1e6; i++)
        count = max(0LL, min(count * factor - delta, limit));

    cout << count;
}