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

    for (int i = 0; i < 2; i++) {
        int pos = 0;
        while (pos + 1 < s.size() && s[pos] >= s[pos + 1])
            pos++;
        s.erase(s.begin() + pos);
    }

    cout << s;
}