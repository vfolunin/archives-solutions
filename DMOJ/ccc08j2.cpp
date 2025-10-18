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

    string s = "ABCDE";

    while (1) {
        int type, count;
        cin >> type >> count;

        if (type == 4)
            break;

        for (int i = 0; i < count; i++) {
            if (type == 1)
                rotate(s.begin(), s.begin() + 1, s.end());
            else if (type == 2)
                rotate(s.begin(), s.end() - 1, s.end());
            else
                swap(s[0], s[1]);
        }
    }

    for (char c : s)
        cout << c << " ";
}