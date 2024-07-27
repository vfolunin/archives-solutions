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
    for (int i = 0; i < s.size(); i++)
        res = max(res, s.substr(0, i) + s.substr(i + 1));

    cout << res;
}