#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size, sum, windowSize, windowSum;
    cin >> size >> sum >> windowSize >> windowSum;

    if (size % windowSize || size / windowSize * windowSum == sum)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}