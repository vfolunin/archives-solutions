#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

char rec(int index, int size, char c) {
    if (!index)
        return c;

    size /= 2;
    index--;
    if (index >= size)
        index -= size;

    return rec(index, size, c - 1);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int index;
    cin >> index;

    cout << rec(index - 1, (1 << 26) - 1, 'z');
}