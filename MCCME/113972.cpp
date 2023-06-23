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

    string cur, res;
    for (char c : s) {
        if (cur.empty() || cur.back() <= c)
            cur.push_back(c);
        else
            cur = string(1, c);
        
        if (res.size() < cur.size())
            res = cur;
    }

    cout << res;
}