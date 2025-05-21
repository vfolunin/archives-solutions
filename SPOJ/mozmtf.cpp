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
    int sum;
    cin >> s >> sum;

    for (char c : s)
        sum -= c - '0';

    string res = to_string(sum) + s;
    for (int i = 1; i <= s.size(); i++)
        res = max(res, s.substr(0, i) + to_string(sum) + s.substr(i));

    cout << res;
}