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

    s.erase(unique(s.begin(), s.end()), s.end());

    cout << s.substr(0, 2 + s.size() % 2);
}