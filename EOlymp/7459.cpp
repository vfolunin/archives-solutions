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

    if (s[0] == '-')
        s.erase(s.begin());

    int res = 1;
    for (int i = 0; i < s.size(); i += 2)
        res *= s[i] - '0';

    cout << res;
}