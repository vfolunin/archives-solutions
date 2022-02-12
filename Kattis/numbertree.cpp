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

    int height;
    string path;
    cin >> height >> path;

    int index = 0;
    for (char c : path)
        index = 2 * index + 1 + (c == 'R');

    cout << (1 << (height + 1)) - 1 - index;
}