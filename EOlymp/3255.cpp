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

    int res = s[0] - '0';
    for (int i = 2; i < s.size(); i += 2) {
        if (s[i - 1] == '+')
            res += s[i] - '0';
        else
            res *= s[i] - '0';
    }

    cout << res;
}