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

    int size = 0;
    while (size * size < s.size())
        size++;

    while (s.size() < size * size)
        s += s.back();

    for (int x = 0; x < size; x++)
        for (int y = 0; y < size; y++)
            cout << s[y * size + x];
}