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

    int to = s.rfind('B');

    string res;
    for (int i = 0; i < to; i++)
        if (s[i] == 'B')
            res += s[i];
    res += s.substr(to);

    cout << res << "\n";
    cout << s.size() - res.size();
}