#include <iostream>
#include <string>
using namespace std;

int main() {
    for (int i = 0; i < 10; i++) {
        string s, l = "DFLT";
        cin >> s;

        int r = 1;
        for (char c : s)
            if (c == 'D' || l.find(c) != -1)
                r *= 2;

        cout << r << "\n";
    }
}