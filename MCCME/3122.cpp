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

    int l = s.find('h'), r = s.rfind('h');

    cout << s.substr(0, l) << s.substr(r + 1) << "\n";
}