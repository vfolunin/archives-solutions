#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long reverse(long long value) {
    string s = to_string(value);
    reverse(s.begin(), s.end());
    return stoll(s);
}

void solve(int test) {
    long long a, b;
    cin >> a >> b;

    cout << "Case " << test << "#: " << reverse(reverse(a) + reverse(b)) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 1; test <= testCount; test++)
        solve(test);
}