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

    string value;
    cin >> value;

    for (int i = 1e3; i < 1e4; i++) {
        string s = to_string(i);

        int a = s[0] - '0' + s[1] - '0';
        int b = s[2] - '0' + s[3] - '0';
        if (a < b)
            swap(a, b);

        if (to_string(a) + to_string(b) == value) {
            cout << i;
            return 0;
        }
    }

    cout << 0;
}