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

    int p = s.find(',');

    cout << s.substr(0, p) << "\n";
    cout << s.substr(p + 1) << "\n";
}