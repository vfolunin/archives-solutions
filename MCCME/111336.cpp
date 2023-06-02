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
    for (int shift = 1; getline(cin, s); shift++) {
        for (char &c : s) {
            if (islower(c))
                c = (c - 'a' + shift) % 26 + 'a';
            else if (isupper(c))
                c = (c - 'A' + shift) % 26 + 'A';
        }
        cout << s << "\n";
    }
}