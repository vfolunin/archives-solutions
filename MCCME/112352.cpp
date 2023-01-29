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

    if (s[0] == '-') {
        cout << "-";
        s = s.substr(1);
    }

    for (int i = 0; i < s.size(); i++) {
        int value = stoi(string(1, s[i]), 0, 16);

        string bin;
        for (int j = 0; j < 4; j++) {
            bin += '0' + value % 2;
            value /= 2;
        }

        while (!i && bin.back() == '0')
            bin.pop_back();

        reverse(bin.begin(), bin.end());

        cout << bin;
    }
}