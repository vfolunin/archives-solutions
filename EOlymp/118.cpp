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

    int mask = 0;
    for (char c : s)
        if (c != '4')
            mask ^= 1 << (c - '1');

    cout << (mask && mask != 7);
}