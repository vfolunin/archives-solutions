#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] != i + '1') {
            cout << -1;
            return 0;
        }
    }

    cout << s.size();
}