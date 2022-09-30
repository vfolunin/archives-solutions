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
        if (c != ' ' || res.empty() || res.back() != ' ')
            res += c;

    cout << res;
}