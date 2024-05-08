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
    cin >> s >> s;

    long long l = 0, r = count(s.begin(), s.end(), 'W'), res = 0;
    for (char c : s) {
        if (c == 'C')
            l++;
        else if (c == 'O')
            res += l * r;
        else
            r--;
    }

    cout << res;
}