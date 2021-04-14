#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    string s;
    cin >> s;

    static string letters = "ACGT";
    long long index = 0;
    for (char c : s)
        index = index * 4 + letters.find(c);

    cout << "Case " << test << ": (" << s.size() << ":" << index << ")\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}