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
    cin >> size;

    string s(size, 'o');
    for (int a = 0, b = 1, c = 1; c <= s.size(); a = b, b = c, c = a + b)
        s[c - 1] = 'O';

    cout << s;
}