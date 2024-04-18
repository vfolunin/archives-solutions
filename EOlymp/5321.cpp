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

    int value = 0;
    for (int bit = 0; bit < 32; bit++)
        value |= (s[max((int)s.size() - 1 - bit, 0)] - '0') << bit;

    cout << value;
}