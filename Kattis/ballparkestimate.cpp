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

    if (s.size() > 1 && s[1] >= '5') {
        if (s[0] < '9')
            s[0]++;
        else
            s = "1" + string(s.size(), '0');
    }
    fill(s.begin() + 1, s.end(), '0');

    cout << s;
}