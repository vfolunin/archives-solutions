#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string ones(const string &s) {
    string res = to_string(count(s.begin(), s.end(), '1'));
    return res == s ? res : ones(res);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    cout << ones(s);
}