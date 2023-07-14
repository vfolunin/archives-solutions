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

    vector<int> circles = { 1, 0, 0, 0, 0, 0, 1, 0, 2, 1 };
    int res = 0;
    for (char c : s)
        res += circles[c - '0'];

    cout << res;
}