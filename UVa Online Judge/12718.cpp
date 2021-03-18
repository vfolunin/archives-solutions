#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    string line;
    cin >> line;

    int res = 0;
    for (int i = 0; i < line.size(); i++) {
        vector<int> k(26);
        int odd = 0;

        for (int j = i; j < line.size(); j++) {
            odd -= k[line[j] - 'a'] % 2;
            k[line[j] - 'a']++;
            odd += k[line[j] - 'a'] % 2;
            res += odd <= 1;
        }
    }

    cout << "Case " << test << ": " << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}