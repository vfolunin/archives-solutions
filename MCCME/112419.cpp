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
    getline(cin, s);

    string res;
    for (char c : s)
        if (isdigit(c))
            res += c;

    sort(res.rbegin(), res.rend());

    if (res.empty())
        cout << -1;
    else if (res[0] == '0')
        cout << 0;
    else
        cout << res;
}