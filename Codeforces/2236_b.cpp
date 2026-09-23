#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int jump;
    string s;
    cin >> jump >> jump >> s;

    for (int i = 0; i + jump < s.size(); i++) {
        if (s[i] == '1') {
            s[i] ^= 1;
            s[i + jump] ^= 1;
        }
    }
    
    cout << (s.find('1') == -1 ? "YES\n" : "NO\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}