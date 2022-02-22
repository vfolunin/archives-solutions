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

    int l, r;
    cin >> l >> r;

    string digits = "123456789";
    set<int> codes;

    do {
        int code = stoi(digits.substr(0, 6));
        if (code < l || r < code)
            continue;

        bool divides = 1;
        for (int i = 0; divides && i < 6; i++)
            divides &= code % (digits[i] - '0') == 0;
        if (!divides)
            continue;
        
        codes.insert(code);
    } while (next_permutation(digits.begin(), digits.end()));

    cout << codes.size();
}