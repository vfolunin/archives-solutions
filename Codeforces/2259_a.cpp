#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int width;
    string s;
    cin >> width >> width >> s;

    int res = 0;
    for (int i = 0; i < s.size(); i += width)
        res += s.find('0', i) >= i + width;
    
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