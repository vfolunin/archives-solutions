#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;
 
bool can(long long l, long long r, long long n) {
    return (l + r) * (r - l + 1) / 2 >= n;
}
 
bool solve() {
    long long groupSize, day;
    if (!(cin >> groupSize >> day))
        return 0;
 
    long long r = groupSize;
    while (!can(groupSize, r, day))
        r *= 2;
 
    long long l = groupSize - 1;
    while (l + 1 < r) {
        long long m = l + (r - l) / 2;
        if (can(groupSize, m, day))
            r = m;
        else
            l = m;
    }
 
    cout << r << "\n";
    return 1;
}
 
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}