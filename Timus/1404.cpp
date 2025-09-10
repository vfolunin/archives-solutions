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

    for (int i = 0; i < s.size(); i++) {
        char c = s[i] - 'a';
        c -= i ? s[i - 1] - 'a' : 5;
        c = (c + 26) % 26 + 'a';
        cout << c;
    }
}