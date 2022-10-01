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

    string a = s.substr(0, (s.size() + 1) / 2);
    string b = s.substr((s.size() + 1) / 2);

    cout << b << a << "\n";
}