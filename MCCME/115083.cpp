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

    for (int i = s.size() - 1; i > 0; i--) {
        if (s[i] <= '4') {
            s[i] = '4';
            s[i - 1] = '5';
            i--;
        }
    }

    cout << s;
}