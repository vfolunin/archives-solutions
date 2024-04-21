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

    if (s[0] == '-') {
        sort(s.rbegin(), s.rend() - 1);
    } else {
        sort(s.begin(), s.end());
        if (s[0] == '0')
            swap(s[0], s[s[1] != '0' ? 1 : 2]);
    }

    cout << s;
}