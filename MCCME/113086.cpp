#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long count, limit4, limit2;
    cin >> count >> limit4 >> limit2;

    long long count4 = min((count + 3) / 4, limit4);
    count = max(count - count4 * 4, 0LL);

    long long count2 = min((count + 1) / 2, limit2);
    count = max(count - count2 * 2, 0LL);

    cout << (count ? -1 : count4 + count2);
}