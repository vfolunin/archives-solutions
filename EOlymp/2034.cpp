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

    string symbols = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

    for (string line; getline(cin, line); ) {
        for (char &c : line)
            if (c != ' ')
                c = symbols[symbols.find(c) - 1];
        cout << line << "\n";
    }
}