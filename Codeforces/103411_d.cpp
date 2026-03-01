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

    string symbols = "ATCG";
    for (int l = 0, r = s.size() - 1; l <= r; l++, r--) {
        if (s[l] != symbols[symbols.find(s[r]) ^ 1]) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
}