#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int n;
    cin >> n;
    cin.ignore();

    if (test > 1)
        cout << "\n";
    cout << "Case " << test << ":\n";

    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);

        string res;
        for (char c : line)
            if (c != ' ' || res.empty() || res.back() != ' ')
                res += c;

        cout << res << "\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    
    for (int test = 1; test <= n; test++)
        solve(test);
}