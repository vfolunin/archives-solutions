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

    cout << "(" << s.substr(0, 3) << ")" << s.substr(3, 3) << "-" << s.substr(6, 2) << "-" << s.substr(8);
}