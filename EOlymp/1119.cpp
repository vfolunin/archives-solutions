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

    char c;
    int size;
    cin >> c >> size;

    cout << size * (size + size * 2 - 1) / 2 << "\n";
    for (int spaces = size - 1, chars = 1; spaces >= 0; spaces--, chars += 2)
        cout << string(spaces, ' ') << string(chars, c) << "\n";
}