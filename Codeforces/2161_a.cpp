#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int rating, threshold, delta, size;
    string s;
    cin >> rating >> threshold >> delta >> size >> s;

    int res = 0;
    for (char c : s) {
        if (c == '1' || rating < threshold) {
            res++;
            rating -= delta;
        }
    }

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}