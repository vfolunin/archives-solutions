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

    string keys = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

    while (1) {
        char c = cin.get();
        if (cin.eof())
            break;

        if (!isspace(c))
            c = keys[keys.find(c) - 1];
        cout << c;
    }
}