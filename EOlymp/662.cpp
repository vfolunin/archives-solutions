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

    string res = s.substr(0, s.size() - 2);

    if (s.substr(s.size() - 2) != "00") {
        int pos = res.size() - 1;
        while (pos >= 0 && res[pos] == '9') {
            res[pos] = '0';
            pos--;
        }
        if (pos < 0)
            res = "1" + res;
        else
            res[pos]++;
    }

    cout << res;
}