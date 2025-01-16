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

    int width;
    string s;
    cin >> width >> s;

    long long cur = 0, res = 0;
    for (int i = width; i < s.size(); i++) {
        if (s[i - width] == s[i])
            cur++;
        else
            cur = 0;
        res += cur;
    }

    cout << res;
}