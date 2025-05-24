#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int n;
    cin >> n;

    vector<int> from = { 44, 49, 54, 59, 64, 69, 74, 79, 100 };
    vector<string> mark = { "F", "D", "C", "B-", "B", "B+", "A-", "A", "A+" };

    cout << "Case " << test << ": " << mark[lower_bound(from.begin(), from.end(), n) - from.begin()] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 1; test <= testCount; test++)
        solve(test);
}