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

    int size;
    string s;
    cin >> size >> s;

    if (s[3] == '1') {
        cout << string(size, '1');
    } else if (s[1] == '1') {
        if (size % 2)
            cout << string(size, '1');
        else
            cout << 0 << string(size - 1, '1');
    } else if (s[0] == '1') {
        cout << string(size - 1, '1') << 0;
    } else if (s[2] == '1') {
        cout << 1 << string(size - 1, '0');
    } else {
        cout << "No solution";
    }
}