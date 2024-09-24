#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int mirror(int value) {
    string s = to_string(value);
    reverse(s.begin(), s.end());
    for (char &c : s) {
        if (c == '2')
            c = '5';
        else if (c == '5')
            c = '2';
    }
    return stoi(s);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int a, b;
    cin >> a >> b;

    cout << (mirror(a) > mirror(b) ? 1 : 2);
}