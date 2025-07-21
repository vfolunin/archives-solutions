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

    int a = 0, b = 0;
    for (char c : s) {
        a += c == 'T';
        b += c == 'H';

        if (max(a, b) >= 11 && max(a, b) - min(a, b) >= 2)
            a = b = 0;
    }

    cout << a << "-" << b;
}