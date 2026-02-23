#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool check(string &code) {
    return !(code[0] ^ code[1] ^ code[3] ^ code[6]) &&
           !(code[0] ^ code[2] ^ code[3] ^ code[5]) &&
           !(code[1] ^ code[2] ^ code[3] ^ code[4]);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string code;
    getline(cin, code);

    code.erase(remove(code.begin(), code.end(), ' '), code.end());

    for (int i = 0; i < code.size(); i++) {
        code[i] ^= 1;

        if (check(code)) {
            for (char c : code)
                cout << c << " ";
            return 0;
        }

        code[i] ^= 1;
    }

    for (char c : code)
        cout << c << " ";
}