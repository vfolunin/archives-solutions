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
    cin >> s >> s;

    for (int i = 0, shift = 1; i < s.size(); i++, shift = shift * 2 % 26)
        s[i] = (s[i] - 'A' + shift) % 26 + 'A';

    cout << s;
}