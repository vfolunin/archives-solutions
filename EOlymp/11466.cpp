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

    string res;
    for (string s; cin >> s; )
        if (res.size() < s.size())
            res = s;

    cout << res;
}