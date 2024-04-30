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

    long long res = -1e18;
    for (int i = s[0] == '-'; i < s.size(); i++) {
        for (int j = i; j < s.size(); j++) {
            swap(s[i], s[j]);
            if (s[0] > '0' || s[0] == '-' && s[1] > '0')
                res = max(res, stoll(s));
            swap(s[i], s[j]);
        }
    }

    cout << res;
}