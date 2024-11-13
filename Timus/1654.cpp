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

    string res;
    for (char c : s)
        if (!res.empty() && res.back() == c)
            res.pop_back();
        else
            res.push_back(c);

    cout << res;
}