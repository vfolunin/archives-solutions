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

    s.erase(remove_if(s.begin(), s.end(), [](char c) { return c % 2 == 0; }), s.end());
    
    cout << (s.empty() ? "0" : s);
}