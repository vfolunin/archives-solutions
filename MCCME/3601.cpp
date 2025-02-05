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

    for (string s; getline(cin, s); ) {
        for (int i = 0; i < s.size(); i++) {
            if (i + 1 == s.size() || !islower(s[i]) || !isupper(s[i + 1])) {
                cout << s[i];
            } else {
                cout << "_?_" << s[i] << s[i + 1] << "_?_";
                i++;
            }
        }
        cout << "\n";
    }
}