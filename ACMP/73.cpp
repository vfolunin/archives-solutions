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
        int code = isdigit(s[i]) ? s[i] - '0' : s[i] - 'A' + 10;
        code = ((code - i - 1) % 27 + 27) % 27;
        cout << (char)(code ? code - 1 + 'a' : ' ');
    }
}