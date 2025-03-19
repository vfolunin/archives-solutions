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
            if (s.substr(i, 3) == "BUG")
                i += 2;
            else
                cout << s[i];
        }
        cout << "\n";
    }
}