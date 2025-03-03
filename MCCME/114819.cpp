#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int rec(long long h1, long long w1, long long h2, long long w2) {
    if (h1 <= h2 && w1 <= w2)
        return 0;
    if (h1 > h2)
        return rec(h1, w1, h2 * 2, w2) + 1;
    else
        return rec(h1, w1, h2, w2 * 2) + 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    long long h1, w1, h2, w2;
    cin >> h1 >> w1 >> h2 >> w2;

    cout << min(rec(h1, w1, h2, w2), rec(w1, h1, h2, w2));
}