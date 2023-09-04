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
        cout << s[i];
        if (i + 1 < s.size() && (s.size() - 1 - i) % 3 == 0)
            cout << ",";
    }
}