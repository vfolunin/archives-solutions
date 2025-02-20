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

    string symbols = "abcdefghijklmnopqrstuvwxyz.,! ";
    string presses = "123123123123123123123123121231";

    int res = 0;
    for (char c : s)
        res += presses[symbols.find(c)] - '0';

    cout << res;
}