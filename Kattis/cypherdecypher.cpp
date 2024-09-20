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

    string digits;
    int size;
    cin >> digits >> size;

    for (int i = 0; i < size; i++) {
        string s;
        cin >> s;

        for (int i = 0; i < s.size(); i++)
            cout << (char)((s[i] - 'A') * (digits[i] - '0') % 26 + 'A');
        cout << "\n";
    }
}