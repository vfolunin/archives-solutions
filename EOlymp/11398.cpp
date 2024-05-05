#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    int res0 = 0, res1 = 0;
    for (int i = 0; i < s.size(); i++) {
        res0 += s[i] != (i % 2 ? '1' : '0');
        res1 += s[i] != (i % 2 ? '0' : '1');
    }

    cout << min(res0, res1);
}