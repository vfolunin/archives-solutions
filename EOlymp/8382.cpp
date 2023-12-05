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

    int res = 0;

    res += find_if(s.begin(), s.end(), [](char c) { return islower(c); }) != s.end();
    res += find_if(s.begin(), s.end(), [](char c) { return isupper(c); }) != s.end();
    res += find_if(s.begin(), s.end(), [](char c) { return isdigit(c); }) != s.end();
    res += find_if(s.begin(), s.end(), [](char c) {
        string symbols = "!\"#$%&'()*+";
        return symbols.find(c) != -1;
    }) != s.end();
    res += s.size() >= 8;

    cout << res;
}