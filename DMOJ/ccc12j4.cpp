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

    int shift;
    string s;
    cin >> shift >> s;

    for (int i = 0; i < s.size(); i++) {
        s[i] -= 'A';
        s[i] = ((s[i] - 3 * (i + 1) - shift) % 26 + 26) % 26;
        s[i] += 'A';
    }

    cout << s;
}